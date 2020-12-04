#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define Process_MAX 10
//建立两个结构体
//第一个结构体,单个进程的信息
typedef struct Process{
	int name;
	int arrive;
	int run;
	int start;
	int finish;
	int turnaround;
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
	//平均带权周转时间
	double average_weight_turnaround;
	//记录进程的执行次序
	int array[Process_MAX];
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

void printProcessTable(ProcessTable* processTable);
//进程调度算法
//1. 先来先服务算法
void FCFS(ProcessTable* processTable){
	//冒泡排序
	for (int bound = 0; bound < processTable->size-1; bound++){
		for (int cur = processTable->size - 1; cur>0; cur--){
			if (processTable->process[cur].arrive < processTable->process[cur - 1].arrive){
				Process temp = processTable->process[cur];
				processTable->process[cur] = processTable->process[cur - 1];
				processTable->process[cur - 1] = temp;
			}
		}
	}
	//计算开始时间和完成时间
	//第一个进程
	processTable->process[0].start = processTable->process[0].arrive;
	//完成时间=开始时间+运行时间
	processTable->process[0].finish = processTable->process[0].start + processTable->process[0].run;

	//后续进程
	for (int i = 1; i < processTable->size; i++){
		//如果该进程在来临时,上一个进程尚未结束或刚刚结束
		if (processTable->process[i - 1].finish >= processTable->process[i].arrive){

			processTable->process[i].start = processTable->process[i - 1].finish;
			processTable->process[i].finish = processTable->process[i].start + processTable->process[i].run;
		}
		else{
			processTable->process[i].start = processTable->process[i].arrive;
			processTable->process[i].finish = processTable->process[i].start + processTable->process[i].run;

		}
	}
	//计算周转时间
	processTable->average_turnaround = 0.0;
	for (int i = 0; i < processTable->size; i++){
		//带权周转时间=完成时间-开始时间
		processTable->process[i].turnaround = processTable->process[i].finish - processTable->process[i].arrive;
		processTable->average_turnaround += (double)processTable->process[i].turnaround;
	}
	//平均周转时间
	processTable->average_turnaround = processTable->average_turnaround / (double)processTable->size;

	//带权周转时间
	processTable->average_weight_turnaround = 0.0;
	for (int i = 0; i < processTable->size; i++){
		//带权周转时间=带权周转时间 / 运行时间
		processTable->process[i].weight_turnaround = (double)processTable->process[i].turnaround / (double) processTable->process[i].run;
		processTable->average_weight_turnaround += (double)processTable->process[i].weight_turnaround;	
	}
	//平均带权周转时间
	processTable->average_weight_turnaround = (double)processTable->average_weight_turnaround / (double)processTable->size;

}
//2. 时间片轮转调度算法
void time(Process* processTable){

}
//3.高响应比优先级调度算法
void HRRN(Process* processTable){

}

//4. 短作业优先算法
//核心思路: 先从时间上考虑,从哪个进程开始,下一进程使用最短作业优先
void SJF(ProcessTable* processTable){
	int count = 0;
	//找到达时间最早的作业并运行它----->放在首行
	for (int cur = processTable->size - 1; cur>0; cur--){
		if (processTable->process[cur].arrive < processTable->process[cur - 1].arrive){
			Process temp = processTable->process[cur];
			processTable->process[cur] = processTable->process[cur - 1];
			processTable->process[cur - 1] = temp;
		}
	}
	processTable->process[count++].start = processTable->process[count].arrive;
	processTable->process[count++].finish = processTable->process[count++].start + processTable->process[count++].run;

	//找最短的作业
	for (int cur = processTable->size - 1; cur>count; cur--){
		if (processTable->process[cur].run < processTable->process[cur - 1].run){
			Process temp = processTable->process[cur];
			processTable->process[cur] = processTable->process[cur - 1];
			processTable->process[cur - 1] = temp;
		}
	}
	
	
	//计算周转时间
	processTable->average_turnaround = 0.0;
	for (int i = 0; i < processTable->size; i++){
		//带权周转时间=完成时间-开始时间
		processTable->process[i].turnaround = processTable->process[i].finish - processTable->process[i].arrive;
		processTable->average_turnaround += (double)processTable->process[i].turnaround;
	}
	//平均周转时间
	processTable->average_turnaround = processTable->average_turnaround / (double)processTable->size;

	//带权周转时间
	processTable->average_weight_turnaround = 0.0;
	for (int i = 0; i < processTable->size; i++){
		//带权周转时间=带权周转时间 / 运行时间
		processTable->process[i].weight_turnaround = (double)processTable->process[i].turnaround / (double)processTable->process[i].run;
		processTable->average_weight_turnaround += (double)processTable->process[i].weight_turnaround;

	}
	//平均带权周转时间
	processTable->average_weight_turnaround = (double)processTable->average_weight_turnaround / (double)processTable->size;

}
//打印进程的信息
void printProcessTable(ProcessTable* processTable){
	printf("                             进程信息\n");
	printf("=====================================================================\n");
	printf("Seq\tName\tArrive\tRun\tStart\tFinish\tTAround\tWTAround\n");
	for (int i = 0; i < processTable->size; i++){
		printf("[%d]\t %d\t %d\t %d\t %d\t %d\t %d\t %3.2f\n", i+1, 
			processTable->process[i].name, processTable->process[i].arrive,
			processTable->process[i].run, processTable->process[i].start,
			processTable->process[i].finish, processTable->process[i].turnaround,
			processTable->process[i].weight_turnaround);
	}
	printf("平均周转时间: %3.2f\n", processTable->average_turnaround);
	printf("平均带权周转时间为:%3.2f\n", processTable->average_weight_turnaround);
	printf("=====================================================================\n");
}
ProcessTable processTable;
int main()
{
	initProcessTable(&processTable);
	FCFS(&processTable);
	printProcessTable(&processTable);
	SJF(&processTable);
	printProcessTable(&processTable);
	system("pause");
	return 0;
}