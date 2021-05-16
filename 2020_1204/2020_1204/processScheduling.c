#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define Process_MAX 10
//���������ṹ��
//��һ���ṹ��,�������̵���Ϣ
typedef struct Process{
	int rank;//ִ�еĴ���
	int name;
	int arrive;
	int run;
	int start;
	int finish;
	int turnaround;
	int wait;
	double weight_turnaround;
	//��־λ
	int flag;
}Process;

//�ڶ����ṹ��,�������̱�
typedef struct ProccessTable{
	//��������
	Process process[Process_MAX];
	//ƽ����תʱ��
	double average_turnaround;
	//ƽ���ȴ�ʱ��
	double average_wait;
	//ƽ����Ȩ��תʱ��
	double average_weight_turnaround;
	//��Ч������
	int size;
}ProcessTable;


//��ʼ��
void initProcessTable(ProcessTable* processTable){
	printf("��������̵�����:");
	scanf("%d",&processTable->size);

	
	//��ʼ������ʱ��͹�������ʱ��
	for (int i = 0; i < processTable->size; i++){
		printf("�������%d���̵�����,����ʱ��͹�������ʱ��:", i + 1);

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

//���ػ��ڶ���ҵ�����㷨�е�ǰ��ִ�еĽ���(��Ҫ��������,����Ḳ������,�������ݶ�ʧ)
int SJFSort(ProcessTable* processTable,int executionProcess,int nowTime){
	//���������ڴ�ŵ�ǰ�Ѿ������ڴ�Ľ��� (�˴���ŵĲ����±�,��Ϊ��ʼ��Ϊ0,�׻���)
	int nowArriveProcess[Process_MAX] = { 0 };
	//��¼���������Ч�洢�Ľ��̸���
	int count = 0;
	//step1. �ҳ���ǰʱ���Ѿ������ڴ�ȴδ��CPUִ�еĽ���
	for (int i = 0; i < processTable->size; i++){
		if (processTable->process[i].flag!=1
			&&processTable->process[i].run <= nowTime){
			nowArriveProcess[count++] = i+1;
		}
	}
	//�ڵ�ǰʱ���֮ǰ�ѵ�����δ��CPUִ�еĽ�������Ϊ0ʱ���ҳ���̵���ҵ
	if (count != 0){
		//step2. �ҳ���Щ����˭����ҵ��̵Ľ��̵��±�
		executionProcess = nowArriveProcess[0] - 1;
		for (int i = 1; i < count; i++){
			if (processTable->process[nowArriveProcess[i] - 1].run>processTable->process[executionProcess].run){
				//����ҵ�϶̵Ľ����±���뽫Ҫִ�еı�����
				executionProcess = nowArriveProcess[i - 1] - 1;
			}else{
				executionProcess = nowArriveProcess[i] - 1;
			}
		}
		return executionProcess;
	}else {
		//����Ѱ�ҵ���ʱ��������δ��CPUִ�еĽ���


	}
	
}
//�Ե�ǰnowtimeʱ��Ϊ��㣬�������ʱ���֮ǰ����ҵ���и���Ӧ�����ȼ�ѡ��
//ѡ������ȱ���ߵ���ҵ
int HRRNSort(ProcessTable* processTable, int executionProcess, int nowTime){
	//���������ڴ�ŵ�ǰ�Ѿ������ڴ�Ľ��� (�˴���ŵĲ����±�,��Ϊ��ʼ��Ϊ0,�׻���)
	int nowArriveProcess[Process_MAX] = { 0 };
	//��¼���������Ч�洢�Ľ��̸���
	int count = 0;
	//step1. �ҳ���ǰʱ���Ѿ������ڴ�ȴδ��CPUִ�еĽ���
	for (int i = 0; i < processTable->size; i++){
		if (processTable->process[i].flag != 1
			&& processTable->process[i].run <= nowTime){
			nowArriveProcess[count++] = i + 1;
			compute
		}
	}
	//step2. �ҳ���Щ����˭����ҵ��̵Ľ��̵��±�
	executionProcess = nowArriveProcess[0] - 1;
	for (int i = 1; i < count; i++){
		if (processTable->process[nowArriveProcess[i] - 1].run>processTable->process[executionProcess].run){
			//����ҵ�϶̵Ľ����±���뽫Ҫִ�еı�����
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
	//step1. ������תʱ��,  �ȴ�ʱ��, ��Ȩ��תʱ��
	processTable->average_turnaround = 0.0;
	processTable->average_weight_turnaround = 0.0;
	processTable->average_wait = 0.0;
	for (int i = 0; i < processTable->size; i++){
		//��תʱ��=���ʱ��-��ʼʱ��
		p[i].turnaround = p[i].finish - p[i].arrive;
		processTable->average_turnaround += (double)p[i].turnaround;
		//�ȴ�ʱ��=��תʱ��-����ʱ��
		p[i].wait = processTable->process[i].turnaround - p[i].run;
		processTable->average_wait += (double)processTable->process[i].wait;
		//��Ȩ��תʱ��=��תʱ�� / ����ʱ��
		p[i].weight_turnaround = (double)p[i].turnaround / (double)p[i].run;
		processTable->average_weight_turnaround += (double)p[i].weight_turnaround;
	}
	//step2. ����ƽ����תʱ�䣬ƽ���ȴ�ʱ��, ƽ����Ȩ��תʱ��
	//ƽ����תʱ��
	processTable->average_turnaround = processTable->average_turnaround / (double)processTable->size;
	//ƽ���ȴ�ʱ��
	processTable->average_wait = processTable->average_wait / (double)processTable->size;
	//ƽ����Ȩ��תʱ��
	processTable->average_weight_turnaround = (double)processTable->average_weight_turnaround / (double)processTable->size;
}

//��ӡ���̵���Ϣ
void printProcessTable(ProcessTable* processTable){
	printf("                             ������Ϣ\n");
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
	printf("ƽ����תʱ��: %3.2f\n", processTable->average_turnaround);
	printf("ƽ���ȴ�ʱ��: %3.2f\n", processTable->average_wait);

	printf("ƽ����Ȩ��תʱ��Ϊ:%3.2f\n", processTable->average_weight_turnaround);
	printf("===========================================================================================\n");
}

//���̵����㷨
//1. �����ȷ����㷨
void FCFS(ProcessTable* processTable){
	Process* p = processTable->process;
	//ð������
	for (int bound = 0; bound < processTable->size-1; bound++){
		for (int cur = processTable->size - 1; cur>0; cur--){
			if (p[cur].arrive < p[cur - 1].arrive){
				Process temp = p[cur];
				p[cur] = p[cur - 1];
				p[cur - 1] = temp;
			}
		}
	}
	//���㿪ʼʱ������ʱ��
	//��һ������
	p[0].start = p[0].arrive;
	//���ʱ��=��ʼʱ��+����ʱ��
	p[0].finish = p[0].start + p[0].run;

	//��������
	for (int i = 1; i < processTable->size; i++){
		//����ý���������ʱ,��һ��������δ������ոս���
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

//2. ����ҵ�����㷨
//����˼·: �ȴ�ʱ���Ͽ���,���ĸ����̿�ʼ,��һ����ʹ�������ҵ����
void SJF(ProcessTable* processTable){
	int count = 1;
	int priorExecutionProcess = 0;
	int executionProcess = 0;
	Process* p = processTable->process;
	//��һ������,�ҵ����翪ʼ������ʱ����̵Ľ��̵������±�
	//executionProcess = SJFSort(processTable, executionProcess, 0);
	for (int cur = processTable->size - 1; cur>0; cur--){
		//step1 �������翪ʼ��
		if (p[cur].arrive < p[cur - 1].arrive){
			executionProcess = cur;
		}else if (p[cur].arrive > p[cur - 1].arrive){
			executionProcess = cur - 1;
		}else{
			//�����ڴ�ʱ����ͬ
			//step2 ��������ʱ����̵� (������ҵ)
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

	//��������
	while (count<=processTable->size){
		//ȡ����ǰ�ѵ���ĵĽ���������ʱ����̵Ľ���
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

//3. ʱ��Ƭ��ת�����㷨
void RR(ProcessTable* processTable){
	compute(processTable);
	printProcessTable(processTable);
}
//4.����Ӧ�����ȼ������㷨
void HRRN(ProcessTable* processTable){
	//��¼��ǰ��ҵ������
	int count = 1;
	//��һ������
	//�ҳ������ύ����ҵ���±�
	int executionProcess = 0;
	int priorExecutionProcess = 0;
	executionProcess = SJFSort(processTable, executionProcess, 0);
	
	Process* p = &processTable->process[executionProcess];
	p->start = p->arrive;
	p->rank = count;
	p->finish = p->arrive + p->run;
	p->flag = 1;
	priorExecutionProcess = executionProcess;
	//��������
	//����ǰ��ҵ����������ϵͳ����ҵ��������������ҵ�ѱ�ִ����ϣ�
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
		printf("1.�����ȷ����㷨\n");
		printf("2.����ҵ�����㷨\n");
		printf("3.ʱ��Ƭ��ת�����㷨\n");
		printf("4.����Ӧ�����ȼ������㷨\n");
		printf("=================================\n");
		printf("����������ѡ��:");
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
		printf("����������\n");
	}
	system("pause");
	return 0;
}
/*
��������̵�����:4
�������1���̵�����,����ʱ��͹�������ʱ��:1 0 7
�������2���̵�����,����ʱ��͹�������ʱ��:2 2 4
�������3���̵�����,����ʱ��͹�������ʱ��:3 4 1
�������4���̵�����,����ʱ��͹�������ʱ��:4 5 4
                             ������Ϣ
===========================================================================================
Num     Seq     Name    Arrive  Run     Start   Finish  TAround Wait    WTAround
[1]      1       1       0       7       0       7       7       0       1.00
[2]      4       2       2       4       12      16      14      10      3.50
[3]      2       3       4       1       7       8       4       3       4.00
[4]      3       4       5       4       8       12      7       3       1.75
ƽ����תʱ��: 8.00
ƽ����Ȩ��תʱ��Ϊ:2.56
===========================================================================================
�밴���������. . .
*/                                                                                    