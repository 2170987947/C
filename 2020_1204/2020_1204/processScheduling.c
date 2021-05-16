#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define Process_MAX 10
//建立两个结构体
//第一个结构体,单个进程的信息
typedef struct Process{
	int rank;//执行的次序
	int name;
	int arrive;
	int run;
	int start;
	int finish;
	int turnaround;
	int wait;
	double weight_turnaround;
	//标志位
	int flag;
}Process;

//第二个结构体,整个进程表
typedef struct ProccessTable{
	//进程数组
	Process process[Process_MAX];
	//平均周转时间
	double average_turnaround;
	//平均等待时间
	double average_wait;
	//平均带权周转时间
	double average_weight_turnaround;
	//有效进程数
	int size;
}ProcessTable;


//初始化
void initProcessTable(ProcessTable* processTable){
	printf("请输入进程的总数:");
	scanf("%d",&processTable->size);

	
	//初始化到达时间和估计运行时间
	for (int i = 0; i < processTable->size; i++){
		printf("请输入第%d进程的名称,到达时间和估计运行时间:", i + 1);

		scanf("%d %d %d", &processTable->process[i].name,
			& processTable->process[i].arrive, &processTable->process[i].run);
	}

	
}
int arriveTimeSortFindFirst(ProcessTable* processTable, int executionProcess, int nowTime){
	Process* p = processTable->process;
	
	for (int bound = 0; bound < processTable->size - 1; bound++){
		for (int cur = processTable->size - 1; cur>0; cur--){
			
			if (p[cur].arrive < p[cur - 1].arrive){
				Process temp = p[cur];
				p[cur] = p[cur - 1];
				p[cur - 1] = temp;
			}
		}
	}
}

//返回基于短作业优先算法中当前需执行的进程(不要进行排序,否则会覆盖数据,导致数据丢失)
int SJFSort(ProcessTable* processTable,int executionProcess,int nowTime){
	//该数组用于存放当前已经到达内存的进程 (此处存放的不是下标,因为初始化为0,易混淆)
	int nowArriveProcess[Process_MAX] = { 0 };
	//记录该数组的有效存储的进程个数
	int count = 0;
	//step1. 找出当前时间已经到达内存却未被CPU执行的进程
	for (int i = 0; i < processTable->size; i++){
		if (processTable->process[i].flag!=1
			&&processTable->process[i].run <= nowTime){
			nowArriveProcess[count++] = i+1;
		}
	}
	//在当前时间点之前已到达且未被CPU执行的进程数不为0时，找出最短的作业
	if (count != 0){
		//step2. 找出这些进程谁的作业最短的进程的下标
		executionProcess = nowArriveProcess[0] - 1;
		for (int i = 1; i < count; i++){
			if (processTable->process[nowArriveProcess[i] - 1].run>processTable->process[executionProcess].run){
				//将作业较短的进程下标存入将要执行的变量中
				executionProcess = nowArriveProcess[i - 1] - 1;
			}else{
				executionProcess = nowArriveProcess[i] - 1;
			}
		}
		return executionProcess;
	}else {
		//否则寻找到达时间最早且未被CPU执行的进程


	}
	
}
//以当前nowtime时间为结点，对在这个时间点之前的作业进行高响应比优先级选择，
//选择出优先比最高的作业
int HRRNSort(ProcessTable* processTable, int executionProcess, int nowTime){
	//该数组用于存放当前已经到达内存的进程 (此处存放的不是下标,因为初始化为0,易混淆)
	int nowArriveProcess[Process_MAX] = { 0 };
	//记录该数组的有效存储的进程个数
	int count = 0;
	//step1. 找出当前时间已经到达内存却未被CPU执行的进程
	for (int i = 0; i < processTable->size; i++){
		if (processTable->process[i].flag != 1
			&& processTable->process[i].run <= nowTime){
			nowArriveProcess[count++] = i + 1;
			compute
		}
	}
	//step2. 找出这些进程谁的作业最短的进程的下标
	executionProcess = nowArriveProcess[0] - 1;
	for (int i = 1; i < count; i++){
		if (processTable->process[nowArriveProcess[i] - 1].run>processTable->process[executionProcess].run){
			//将作业较短的进程下标存入将要执行的变量中
			executionProcess = nowArriveProcess[i - 1] - 1;
		}
		else{
			executionProcess = nowArriveProcess[i] - 1;
		}
	}
	return executionProcess;
}
void compute(ProcessTable* processTable){
	Process* p = processTable->process;
	//step1. 计算周转时间,  等待时间, 带权周转时间
	processTable->average_turnaround = 0.0;
	processTable->average_weight_turnaround = 0.0;
	processTable->average_wait = 0.0;
	for (int i = 0; i < processTable->size; i++){
		//周转时间=完成时间-开始时间
		p[i].turnaround = p[i].finish - p[i].arrive;
		processTable->average_turnaround += (double)p[i].turnaround;
		//等待时间=周转时间-运行时间
		p[i].wait = processTable->process[i].turnaround - p[i].run;
		processTable->average_wait += (double)processTable->process[i].wait;
		//带权周转时间=周转时间 / 运行时间
		p[i].weight_turnaround = (double)p[i].turnaround / (double)p[i].run;
		processTable->average_weight_turnaround += (double)p[i].weight_turnaround;
	}
	//step2. 计算平均周转时间，平均等待时间, 平均带权周转时间
	//平均周转时间
	processTable->average_turnaround = processTable->average_turnaround / (double)processTable->size;
	//平均等待时间
	processTable->average_wait = processTable->average_wait / (double)processTable->size;
	//平均带权周转时间
	processTable->average_weight_turnaround = (double)processTable->average_weight_turnaround / (double)processTable->size;
}

//打印进程的信息
void printProcessTable(ProcessTable* processTable){
	printf("                             进程信息\n");
	printf("===========================================================================================\n");
	printf("Num\tSeq\tName\tArrive\tRun\tStart\tFinish\tTAround\tWait\tWTAround\n");
	for (int i = 0; i < processTable->size; i++){
		printf("[%d]\t %d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\t %3.2f\n", i + 1,
			processTable->process[i].rank, processTable->process[i].name, 
			processTable->process[i].arrive,processTable->process[i].run, 
			processTable->process[i].start,processTable->process[i].finish, 
			processTable->process[i].turnaround, processTable->process[i].wait,
			processTable->process[i].weight_turnaround);
	}
	printf("平均周转时间: %3.2f\n", processTable->average_turnaround);
	printf("平均等待时间: %3.2f\n", processTable->average_wait);

	printf("平均带权周转时间为:%3.2f\n", processTable->average_weight_turnaround);
	printf("===========================================================================================\n");
}

//进程调度算法
//1. 先来先服务算法
void FCFS(ProcessTable* processTable){
	Process* p = processTable->process;
	//冒泡排序
	for (int bound = 0; bound < processTable->size-1; bound++){
		for (int cur = processTable->size - 1; cur>0; cur--){
			if (p[cur].arrive < p[cur - 1].arrive){
				Process temp = p[cur];
				p[cur] = p[cur - 1];
				p[cur - 1] = temp;
			}
		}
	}
	//计算开始时间和完成时间
	//第一个进程
	p[0].start = p[0].arrive;
	//完成时间=开始时间+运行时间
	p[0].finish = p[0].start + p[0].run;

	//后续进程
	for (int i = 1; i < processTable->size; i++){
		//如果该进程在来临时,上一个进程尚未结束或刚刚结束
		if (p[i - 1].finish >= processTable->process[i].arrive){

			p[i].start = p[i - 1].finish;
			p[i].finish = p[i].start + p[i].run;
		}
		else{
			p[i].start = p[i].arrive;
			p[i].finish = p[i].start + p[i].run;

		}
	}
	compute(processTable);
	printProcessTable(processTable);

}

//2. 短作业优先算法
//核心思路: 先从时间上考虑,从哪个进程开始,下一进程使用最短作业优先
void SJF(ProcessTable* processTable){
	int count = 1;
	int priorExecutionProcess = 0;
	int executionProcess = 0;
	Process* p = processTable->process;
	//第一个进程,找到最早开始且运行时间最短的进程的数组下标
	//executionProcess = SJFSort(processTable, executionProcess, 0);
	for (int cur = processTable->size - 1; cur>0; cur--){
		//step1 先找最早开始的
		if (p[cur].arrive < p[cur - 1].arrive){
			executionProcess = cur;
		}else if (p[cur].arrive > p[cur - 1].arrive){
			executionProcess = cur - 1;
		}else{
			//进入内存时间相同
			//step2 再找运行时间最短的 (即短作业)
			if (p[cur].run > p[cur - 1].run){
				executionProcess = cur - 1;
			}
			else{
				executionProcess = cur;
			}
		}
	}
	p[executionProcess].rank = count;
	p[executionProcess].start = p[executionProcess].arrive;
	p[executionProcess].finish = p[executionProcess].start + p[executionProcess].run;
	p[executionProcess].flag = 1;
	priorExecutionProcess = executionProcess;

	//后续进程
	while (count<=processTable->size){
		//取出当前已到达的的进程且运行时间最短的进程
		executionProcess = SJFSort(processTable, executionProcess, p[priorExecutionProcess].finish);
		p[executionProcess].rank = count+1;
		p[executionProcess].start = p[priorExecutionProcess].finish;
		p[executionProcess].finish = p[executionProcess].start + p[executionProcess].run;
		p[executionProcess].flag = 1;
		count++;
		priorExecutionProcess = executionProcess;
	}
	compute(processTable);
	printProcessTable(processTable);
}

//3. 时间片轮转调度算法
void RR(ProcessTable* processTable){
	compute(processTable);
	printProcessTable(processTable);
}
//4.高响应比优先级调度算法
void HRRN(ProcessTable* processTable){
	//记录当前作业的数量
	int count = 1;
	//第一个进程
	//找出最早提交的作业的下标
	int executionProcess = 0;
	int priorExecutionProcess = 0;
	executionProcess = SJFSort(processTable, executionProcess, 0);
	
	Process* p = &processTable->process[executionProcess];
	p->start = p->arrive;
	p->rank = count;
	p->finish = p->arrive + p->run;
	p->flag = 1;
	priorExecutionProcess = executionProcess;
	//后续进程
	//当当前作业的数量大于系统中作业的数量（表明作业已被执行完毕）
	while (count<=processTable->size){
		executionProcess = HRRNSort(processTable, executionProcess, processTable->process[executionProcess].finish);
		Process* p = &processTable->process[executionProcess];
		p->start = processTable->process[priorExecutionProcess].finish;
		p->arrive = p->start + p->run;
		p->rank = count + 1;
		p->flag = 1;
		priorExecutionProcess = executionProcess;
		count++;
	}
	compute(processTable);
	printProcessTable(processTable);
}
int menu(){
	int choice;
	while (1){
		printf("=================================\n");
		printf("1.先来先服务算法\n");
		printf("2.短作业优先算法\n");
		printf("3.时间片轮转调度算法\n");
		printf("4.高响应比优先级调度算法\n");
		printf("=================================\n");
		printf("请输入您的选择:");
		scanf("%d", &choice);
		if (choice > 4 || choice < 1){
			continue;
		}
		break;
	}
	return choice;
}

ProcessTable processTable;
int main()
{  
	initProcessTable(&processTable);
	int choice = menu();
	if (choice == 1){
		FCFS(&processTable);	
	}else if(choice == 2){
		SJF(&processTable);
	}else if (choice == 3){
		RR(&processTable);
	}else if (choice == 4) {
		HRRN(&processTable);
	}else{
		printf("您输入有误\n");
	}
	system("pause");
	return 0;
}
/*
请输入进程的总数:4
请输入第1进程的名称,到达时间和估计运行时间:1 0 7
请输入第2进程的名称,到达时间和估计运行时间:2 2 4
请输入第3进程的名称,到达时间和估计运行时间:3 4 1
请输入第4进程的名称,到达时间和估计运行时间:4 5 4
                             进程信息
===========================================================================================
Num     Seq     Name    Arrive  Run     Start   Finish  TAround Wait    WTAround
[1]      1       1       0       7       0       7       7       0       1.00
[2]      4       2       2       4       12      16      14      10      3.50
[3]      2       3       4       1       7       8       4       3       4.00
[4]      3       4       5       4       8       12      7       3       1.75
平均周转时间: 8.00
平均带权周转时间为:2.56
===========================================================================================
请按任意键继续. . .
*/                                                                                    