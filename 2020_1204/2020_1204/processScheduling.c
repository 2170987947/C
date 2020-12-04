#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define Process_MAX 10
//���������ṹ��
//��һ���ṹ��,�������̵���Ϣ
typedef struct Process{
	int name;
	int arrive;
	int run;
	int start;
	int finish;
	int turnaround;
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
	//ƽ����Ȩ��תʱ��
	double average_weight_turnaround;
	//��¼���̵�ִ�д���
	int array[Process_MAX];
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

void printProcessTable(ProcessTable* processTable);
//���̵����㷨
//1. �����ȷ����㷨
void FCFS(ProcessTable* processTable){
	//ð������
	for (int bound = 0; bound < processTable->size-1; bound++){
		for (int cur = processTable->size - 1; cur>0; cur--){
			if (processTable->process[cur].arrive < processTable->process[cur - 1].arrive){
				Process temp = processTable->process[cur];
				processTable->process[cur] = processTable->process[cur - 1];
				processTable->process[cur - 1] = temp;
			}
		}
	}
	//���㿪ʼʱ������ʱ��
	//��һ������
	processTable->process[0].start = processTable->process[0].arrive;
	//���ʱ��=��ʼʱ��+����ʱ��
	processTable->process[0].finish = processTable->process[0].start + processTable->process[0].run;

	//��������
	for (int i = 1; i < processTable->size; i++){
		//����ý���������ʱ,��һ��������δ������ոս���
		if (processTable->process[i - 1].finish >= processTable->process[i].arrive){

			processTable->process[i].start = processTable->process[i - 1].finish;
			processTable->process[i].finish = processTable->process[i].start + processTable->process[i].run;
		}
		else{
			processTable->process[i].start = processTable->process[i].arrive;
			processTable->process[i].finish = processTable->process[i].start + processTable->process[i].run;

		}
	}
	//������תʱ��
	processTable->average_turnaround = 0.0;
	for (int i = 0; i < processTable->size; i++){
		//��Ȩ��תʱ��=���ʱ��-��ʼʱ��
		processTable->process[i].turnaround = processTable->process[i].finish - processTable->process[i].arrive;
		processTable->average_turnaround += (double)processTable->process[i].turnaround;
	}
	//ƽ����תʱ��
	processTable->average_turnaround = processTable->average_turnaround / (double)processTable->size;

	//��Ȩ��תʱ��
	processTable->average_weight_turnaround = 0.0;
	for (int i = 0; i < processTable->size; i++){
		//��Ȩ��תʱ��=��Ȩ��תʱ�� / ����ʱ��
		processTable->process[i].weight_turnaround = (double)processTable->process[i].turnaround / (double) processTable->process[i].run;
		processTable->average_weight_turnaround += (double)processTable->process[i].weight_turnaround;	
	}
	//ƽ����Ȩ��תʱ��
	processTable->average_weight_turnaround = (double)processTable->average_weight_turnaround / (double)processTable->size;

}
//2. ʱ��Ƭ��ת�����㷨
void time(Process* processTable){

}
//3.����Ӧ�����ȼ������㷨
void HRRN(Process* processTable){

}

//4. ����ҵ�����㷨
//����˼·: �ȴ�ʱ���Ͽ���,���ĸ����̿�ʼ,��һ����ʹ�������ҵ����
void SJF(ProcessTable* processTable){
	int count = 0;
	//�ҵ���ʱ���������ҵ��������----->��������
	for (int cur = processTable->size - 1; cur>0; cur--){
		if (processTable->process[cur].arrive < processTable->process[cur - 1].arrive){
			Process temp = processTable->process[cur];
			processTable->process[cur] = processTable->process[cur - 1];
			processTable->process[cur - 1] = temp;
		}
	}
	processTable->process[count++].start = processTable->process[count].arrive;
	processTable->process[count++].finish = processTable->process[count++].start + processTable->process[count++].run;

	//����̵���ҵ
	for (int cur = processTable->size - 1; cur>count; cur--){
		if (processTable->process[cur].run < processTable->process[cur - 1].run){
			Process temp = processTable->process[cur];
			processTable->process[cur] = processTable->process[cur - 1];
			processTable->process[cur - 1] = temp;
		}
	}
	
	
	//������תʱ��
	processTable->average_turnaround = 0.0;
	for (int i = 0; i < processTable->size; i++){
		//��Ȩ��תʱ��=���ʱ��-��ʼʱ��
		processTable->process[i].turnaround = processTable->process[i].finish - processTable->process[i].arrive;
		processTable->average_turnaround += (double)processTable->process[i].turnaround;
	}
	//ƽ����תʱ��
	processTable->average_turnaround = processTable->average_turnaround / (double)processTable->size;

	//��Ȩ��תʱ��
	processTable->average_weight_turnaround = 0.0;
	for (int i = 0; i < processTable->size; i++){
		//��Ȩ��תʱ��=��Ȩ��תʱ�� / ����ʱ��
		processTable->process[i].weight_turnaround = (double)processTable->process[i].turnaround / (double)processTable->process[i].run;
		processTable->average_weight_turnaround += (double)processTable->process[i].weight_turnaround;

	}
	//ƽ����Ȩ��תʱ��
	processTable->average_weight_turnaround = (double)processTable->average_weight_turnaround / (double)processTable->size;

}
//��ӡ���̵���Ϣ
void printProcessTable(ProcessTable* processTable){
	printf("                             ������Ϣ\n");
	printf("=====================================================================\n");
	printf("Seq\tName\tArrive\tRun\tStart\tFinish\tTAround\tWTAround\n");
	for (int i = 0; i < processTable->size; i++){
		printf("[%d]\t %d\t %d\t %d\t %d\t %d\t %d\t %3.2f\n", i+1, 
			processTable->process[i].name, processTable->process[i].arrive,
			processTable->process[i].run, processTable->process[i].start,
			processTable->process[i].finish, processTable->process[i].turnaround,
			processTable->process[i].weight_turnaround);
	}
	printf("ƽ����תʱ��: %3.2f\n", processTable->average_turnaround);
	printf("ƽ����Ȩ��תʱ��Ϊ:%3.2f\n", processTable->average_weight_turnaround);
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