#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define PROCESS_MAX 10
//��Դ����
#define RESOURCE_KIND 4
//ϵͳ�еĸ�����Դ����
#define A_MAX 3
#define B_MAX 9
#define C_MAX 14
#define D_MAX 14
//���������ṹ��

//һ������Դ�ķ���
typedef struct Resource{
	int a;
	int b;
	int c;
	int d;
}Resource;

//һ���ǽ��̵���Ϣ
typedef struct Process{
	//��������
	//�����Դ��
	Resource max;
	//�ѷ�����Դ��
	Resource allocation;
	//������Դ��
	Resource need;
	
	//�ɹ�������Դ��
	Resource work;
	//�ɹ����ĺ��ѷ������Դ�ܺ�
	//ʵ���Ͼ��Ǹý���������ϵͳ�п�ʹ�õ���Դ��
	Resource work_allocation;
	//�ý��̵ı�־λ.��ʾ�ý����Ƿ��Ѿ�������
	int finish;
}Process;

//��һ�����������̵���Ϣ
typedef struct AllProcess{
	Process process[PROCESS_MAX];
	//ϵͳ��ʣ����Դ��
	Resource available;
	//ϵͳ����Ч������
	int size;
	//��ȫ���к�
	int array[PROCESS_MAX];
}AllProcess;

//�Խ��̵ĸ�����Դ���г�ʼ��
void initAllProcess(AllProcess* allProcess){
	printf("�������ϵͳ�Ľ�����:");
	scanf("%d", &allProcess->size);
	for (int i = 0; i < allProcess->size; i++){
		printf("�������%d�����̵�allocation��Դ�������\n", i+1);
		printf("A B C D\n");
		scanf("%d %d %d %d",
		&allProcess->process[i].allocation.a,
		&allProcess->process[i].allocation.b,
		&allProcess->process[i].allocation.c,
		&allProcess->process[i].allocation.d);

		printf("�������%d�����̵�need��Դ���\n", i+1);
		printf("A B C D\n");
		scanf("%d %d %d %d",
		&allProcess->process[i].need.a,
		&allProcess->process[i].need.b,
		&allProcess->process[i].need.c,
		&allProcess->process[i].need.d);

		//��ÿ�����̵ĸ�����Դ�������
		allProcess->process[i].max.a = allProcess->process[i].allocation.a + allProcess->process[i].need.a;
		allProcess->process[i].max.b = allProcess->process[i].allocation.b + allProcess->process[i].need.b;
		allProcess->process[i].max.c = allProcess->process[i].allocation.c + allProcess->process[i].need.c;
		allProcess->process[i].max.d = allProcess->process[i].allocation.d + allProcess->process[i].need.d;

		//ÿ�����̵ı�־λ��Ϊ0,��ʾ����δ������
		allProcess->process[i].finish = 0;
	}
	
}

//��ϵͳ��ʣ����Դ��
void remainResource(AllProcess* allProcess){
	//for (int kind = 0; kind < RESOURCE_KIND; kind++){
	//��ָ��***
		Resource* resource = &allProcess->available;
		resource->a = 0;
		resource->b = 0;
		resource->c = 0;
		resource->d = 0;

		for (int i = 0; i < allProcess->size; i++){
			resource->a += allProcess->process[i].allocation.a;
			resource->b += allProcess->process[i].allocation.b;
			resource->c += allProcess->process[i].allocation.c;
			resource->d += allProcess->process[i].allocation.d;

		}
		resource->a = A_MAX - resource->a;
		resource->b = B_MAX - resource->b;
		resource->c = C_MAX - resource->c;
		resource->d = D_MAX - resource->d;
}

//�Ƿ���ڰ�ȫ����
//���ڷ���1
//�����ڷ���0
int isSecureArray(AllProcess* allProcess){
	//��ȫ���кõ��±�
	int count = 0;
	//���жϴ��ĸ����̿�ʼ,Ȼ��ϵͳ��ʣ����Դ�Ƿ������.
	for (int i = 0; i<allProcess->size; i++){
		

		//��ϵͳ��ʣ����Դ�����ڵ�����ĳ��������Ҫ����Դ��,��������
		if (allProcess->available.a>=allProcess->process[i].need.a
			&&allProcess->available.b >= allProcess->process[i].need.b
			&&allProcess->available.c >= allProcess->process[i].need.c
			&&allProcess->available.d >= allProcess->process[i].need.d){
			

			//�ɹ�������Դ(�Է���)��ʼ��work
			allProcess->process[i].work.a = allProcess->available.a;
			allProcess->process[i].work.b = allProcess->available.b;
			allProcess->process[i].work.c = allProcess->available.c;
			allProcess->process[i].work.d = allProcess->available.d;

			//���иý���,�����־λ��Ϊ1.
			allProcess->process[i].finish = 1;
			//����i����д�밲ȫ���к���
			allProcess->array[count++] = i;
		

			//�ͷŸý��̺�,ϵͳ�пɹ�������Դwork-allocation
			allProcess->process[i].work_allocation.a = allProcess->process[i].work.a + allProcess->process[i].allocation.a;
			allProcess->process[i].work_allocation.b = allProcess->process[i].work.b + allProcess->process[i].allocation.b;
			allProcess->process[i].work_allocation.c = allProcess->process[i].work.c + allProcess->process[i].allocation.c;
			allProcess->process[i].work_allocation.d = allProcess->process[i].work.d + allProcess->process[i].allocation.d;
			
			//�ҵ���һ������,����ʼ����,������ѭ��
			break;
		}
		
	}
	//��¼��ȫ������û������
	int count1 = 0;
	

	//1. ����ȫ������������ʱ,��count���������±�ʱ
	//2. ��������Դ����,ϵͳ�н��̲��ܹ�ȫ������
	//ѭ������
	while (count<allProcess->size && count1!=count){
		//������forѭ����count1==count
		//�����������������̱�û�п������еĽ���
		//˵�������ڰ�ȫ����
	
		//��������˱仯,��ѷ����仯���ֵ����count1
		//�Է�������ж����Ƿ����仯
		count1 = count;
		for (int i = 0; i<allProcess->size; i++){

			//����־λ��Ϊ0,�Ҹո��ͷŵ���Դ�����ڵ�����ĳ��������Ҫ����Դ��,��������
			if (allProcess->process[i].finish!=1
				&&allProcess->process[allProcess->array[count - 1]].work_allocation.a >= allProcess->process[i].need.a
				&&allProcess->process[allProcess->array[count - 1]].work_allocation.b >= allProcess->process[i].need.b
				&&allProcess->process[allProcess->array[count - 1]].work_allocation.c >= allProcess->process[i].need.c
				&&allProcess->process[allProcess->array[count - 1]].work_allocation.d >= allProcess->process[i].need.d){

				//ϵͳ��Ϊ�ý��̿ɹ�������Դ
				//���ո���������������ͷŵ���Դ
				allProcess->process[i].work.a = allProcess->process[allProcess->array[count - 1]].work_allocation.a;
				allProcess->process[i].work.b = allProcess->process[allProcess->array[count - 1]].work_allocation.b;
				allProcess->process[i].work.c = allProcess->process[allProcess->array[count - 1]].work_allocation.c;
				allProcess->process[i].work.d = allProcess->process[allProcess->array[count - 1]].work_allocation.d;

				//���иý���,�����־λ��Ϊ1.
				allProcess->process[i].finish = 1;
				//����i����д�밲ȫ���к���
				allProcess->array[count++] = i;

				//�ͷŸý��̺�,ϵͳ�пɹ�������Դwork-allocation
				allProcess->process[i].work_allocation.a = allProcess->process[i].work.a + allProcess->process[i].allocation.a;
				allProcess->process[i].work_allocation.b = allProcess->process[i].work.b + allProcess->process[i].allocation.b;
				allProcess->process[i].work_allocation.c = allProcess->process[i].work.c + allProcess->process[i].allocation.c;
				allProcess->process[i].work_allocation.d = allProcess->process[i].work.d + allProcess->process[i].allocation.d;
			}
		}
	}
	//����1 ������ڰ�ȫ����
	if (count >= allProcess->size){
		return 1;
	}
	return 0;
}


//ĳ����������Դ,ϵͳ�Ƿ�������
//��ӡ���̸�����Դ����Ϣ
void print(AllProcess* allProcess){

	printf("\t\t\t\t���̸�����Դ���\n");
	printf("==============================================================================================================\n");
	printf("      \t\t  Max\t\t\t\t\tAllocation\t\t\t\tNeed\n");
	printf("��Դ����| A\tB\tC\tD\t|\tA\tB\tC\tD\t|\tA\tB\tC\tD\n");

	for (int i = 0; i < allProcess->size; i++){
		printf("[����%d]\t| %d\t%d\t%d\t%d\t|\t", i + 1,
			allProcess->process[i].max.a,
			allProcess->process[i].max.b,
			allProcess->process[i].max.c,
			allProcess->process[i].max.d);

		printf("%d\t%d\t%d\t%d\t|\t",
			allProcess->process[i].allocation.a,
			allProcess->process[i].allocation.b,
			allProcess->process[i].allocation.c,
			allProcess->process[i].allocation.d);

		printf("%d\t%d\t%d\t%d\n",
			allProcess->process[i].need.a,
			allProcess->process[i].need.b,
			allProcess->process[i].need.c,
			allProcess->process[i].need.d);
	}
	printf("==============================================================================================================\n");

	//����ϵͳʣ����Դ��
	printf("\tϵͳʣ����Դ��\n");
	printf("\tAvailable\n");

	printf("A\tB\tC\tD\n");
	printf("%d\t%d\t%d\t%d\n", allProcess->available.a, allProcess->available.b,
		allProcess->available.c, allProcess->available.d);
}

//����ָ�����͵�����ϵͳ
AllProcess allProcess;

int main()
{
	initAllProcess(&allProcess);
	remainResource(&allProcess);
	print(&allProcess);
	if (isSecureArray(&allProcess) == 1){
		printf("���ڰ�ȫ����\n");
		printf("��ȫ����Ϊ:");
		for (int i = 0; i < allProcess.size; i++){
			//��������һ�����,�Ͳ���->
			if (i == allProcess.size - 1){
				printf("%d\n", allProcess.array[i] + 1);
			}else{
				printf("%d->", allProcess.array[i] + 1);
			}
		}
	}
	system("pause");
	return 0;
}