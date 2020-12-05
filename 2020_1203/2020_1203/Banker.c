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
	//��ȫ���к� (��0��ʼ)
	int array[PROCESS_MAX];
}AllProcess;

//�Խ��̵ĸ�����Դ���г�ʼ��
void initAllProcess(AllProcess* allProcess){
	printf("�������ϵͳ�Ľ�����:");
	scanf("%d", &allProcess->size);
	Process* p = allProcess->process;
	for (int i = 0; i < allProcess->size; i++){
		printf("�������%d�����̵�allocation��Դ�������\n", i+1);
		printf("A B C D\n");
		scanf("%d %d %d %d",
		&p[i].allocation.a,
		&p[i].allocation.b,
		&p[i].allocation.c,
		&p[i].allocation.d);

		printf("�������%d�����̵�need��Դ���\n", i+1);
		printf("A B C D\n");
		scanf("%d %d %d %d",&p[i].need.a,&p[i].need.b,
			&p[i].need.c,&p[i].need.d);

		//��ÿ�����̵ĸ�����Դ�������
		p[i].max.a = p[i].allocation.a + p[i].need.a;
		p[i].max.b = p[i].allocation.b + p[i].need.b;
		p[i].max.c = p[i].allocation.c + p[i].need.c;
		      p[i].max.d = p[i].allocation.d + p[i].need.d;

		//ÿ�����̵ı�־λ��Ϊ0,��ʾ����δ������
		p[i].finish = 0;
	}
	
}

//��ϵͳ��ʣ����Դ��
void remainResource(AllProcess* allProcess){
	//for (int kind = 0; kind < RESOURCE_KIND; kind++){
	Process* p=allProcess->process;
	//��ָ��***
		Resource* resource = &allProcess->available;
		resource->a = 0;
		resource->b = 0;
		resource->c = 0;
		resource->d = 0;

		for (int i = 0; i < allProcess->size; i++){
			resource->a += p[i].allocation.a;
			resource->b += p[i].allocation.b;
			resource->c += p[i].allocation.c;
			resource->d += p[i].allocation.d;

		}
		resource->a = A_MAX - resource->a;
		resource->b = B_MAX - resource->b;
		resource->c = C_MAX - resource->c;
		resource->d = D_MAX - resource->d;
}

//ĳ����������Դ,ϵͳ�Ƿ�������
//��ӡ���̸�����Դ����Ϣ
void print(AllProcess* allProcess){
	Process* p = allProcess->process;
	printf("\t\t\t\t���̸�����Դ���\n");
	printf("==============================================================================================================\n");
	printf("      \t\t  Max\t\tAllocation\t\t\tNeed\n");
	printf("��Դ����| A\tB\tC\tD|A\tB\tC\tD|A\tB\tC\tD\n");

	for (int i = 0; i < allProcess->size; i++){
		printf("[����%d]\t| %d\t%d\t%d\t%d |", i + 1,
			p[i].max.a, p[i].max.b, p[i].max.c, p[i].max.d);

		printf("%d\t%d\t%d\t%d |",
			p[i].allocation.a, p[i].allocation.b,
			p[i].allocation.c, p[i].allocation.d);

		printf("%d\t%d\t%d\t%d\n",
			p[i].need.a, p[i].need.b, p[i].need.c, p[i].need.d);
	}
	printf("\n");

	printf("\t\t\t\t�м�����\n");
	printf("      \t\t  Work\t\t\tAllocation\t\tNeed\t\t\tWork+Allocation\n");
	printf("��Դ����| A\tB\tC\tD|A\tB\tC\tD|A\tB\tC\tD|A\tB\tC\tD\t\n");

	for (int i = 0; i < allProcess->size; i++){
		printf("[����%d]\t| %d\t%d\t%d\t%d |", i + 1,
			p[i].work.a, p[i].work.b, p[i].work.c, p[i].work.d);

		printf("%d\t%d\t%d\t%d |",
			p[i].allocation.a, p[i].allocation.b,
			p[i].allocation.c, p[i].allocation.d);

		printf("%d\t%d\t%d\t%d |",
			p[i].need.a, p[i].need.b, p[i].need.c, p[i].need.d);

		printf("%d\t%d\t%d\t%d\n",
			p[i].work_allocation.a, p[i].work_allocation.b, p[i].work_allocation.c, p[i].work_allocation.d);
	}
	printf("==============================================================================================================\n");
	//����ϵͳʣ����Դ��
	printf("\tϵͳʣ����Դ��\n");
	printf("\tAvailable\n");

	printf("A\tB\tC\tD\n");
	printf("%d\t%d\t%d\t%d\n",
		allProcess->available.a, allProcess->available.b,
		allProcess->available.c, allProcess->available.d);
}

//�Ƿ���ڰ�ȫ����
//���ڷ���1
//�����ڷ���0
int isSecureArray(AllProcess* allProcess){
	Process* p = allProcess->process;
	//��ȫ���кõ��±�
	int count = 0;
	//���жϴ��ĸ����̿�ʼ,Ȼ��ϵͳ��ʣ����Դ�Ƿ������.
	for (int i = 0; i<allProcess->size; i++){
		//��ϵͳ��ʣ����Դ�����ڵ�����ĳ��������Ҫ����Դ��,��������
		if (allProcess->available.a>=p[i].need.a
			&&allProcess->available.b >= p[i].need.b
			&&allProcess->available.c >= p[i].need.c
			&&allProcess->available.d >= p[i].need.d){	

			//�ɹ�������Դ(�Է���)��ʼ��work
			(p+i)->work.a = allProcess->available.a;
			p[i].work.b = allProcess->available.b;
			p[i].work.c = allProcess->available.c;
			p[i].work.d = allProcess->available.d;

			//���иý���,�����־λ��Ϊ1.
			p[i].finish = 1;
			//����i����д�밲ȫ���к���
			allProcess->array[count++] = i;

			//�ͷŸý��̺�,ϵͳ�пɹ�������Դwork-allocation
			p[i].work_allocation.a = p[i].work.a + p[i].allocation.a;
			p[i].work_allocation.b = p[i].work.b + p[i].allocation.b;
			p[i].work_allocation.c = p[i].work.c + p[i].allocation.c;
			p[i].work_allocation.d = p[i].work.d + p[i].allocation.d;
			
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
			if (p[i].finish!=1
				&&p[allProcess->array[count - 1]].work_allocation.a >= p[i].need.a
				&&p[allProcess->array[count - 1]].work_allocation.b >= p[i].need.b
				&&p[allProcess->array[count - 1]].work_allocation.c >= p[i].need.c
				&&p[allProcess->array[count - 1]].work_allocation.d >= p[i].need.d){

				//ϵͳ��Ϊ�ý��̿ɹ�������Դ
				//���ո���������������ͷŵ���Դ
				p[i].work.a = p[allProcess->array[count - 1]].work_allocation.a;
				p[i].work.b = p[allProcess->array[count - 1]].work_allocation.b;
				p[i].work.c = p[allProcess->array[count - 1]].work_allocation.c;
				p[i].work.d = p[allProcess->array[count - 1]].work_allocation.d;

				//���иý���,�����־λ��Ϊ1.
				allProcess->process[i].finish = 1;
				//����i����д�밲ȫ���к���
				allProcess->array[count++] = i;

				//�ͷŸý��̺�,ϵͳ�пɹ�������Դwork-allocation
				p[i].work_allocation.a = p[i].work.a + p[i].allocation.a;
				p[i].work_allocation.b = p[i].work.b + p[i].allocation.b;
				p[i].work_allocation.c = p[i].work.c + p[i].allocation.c;
				p[i].work_allocation.d = p[i].work.d + p[i].allocation.d;
			}
		}
	}
	print(allProcess);
	//����1 ������ڰ�ȫ����
	if (count >= allProcess->size){
		return 1;
	}
	return 0;
}

//����ָ�����͵�����ϵͳ
AllProcess allProcess;

int main()
{
	initAllProcess(&allProcess);
	remainResource(&allProcess);

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
	}else{
		printf("�����ڰ�ȫ����\n");
	}
	system("pause");
	return 0;
}
/*
�������ϵͳ�Ľ�����:5
�������1�����̵�allocation��Դ�������
A B C D
0 0 3 2
�������1�����̵�need��Դ���
A B C D
0 0 1 2
�������2�����̵�allocation��Դ�������
A B C D
1 0 0 0
�������2�����̵�need��Դ���
A B C D
1 6 9 5
�������3�����̵�allocation��Դ�������
A B C D
1 3 5 4
�������3�����̵�need��Դ���
A B C D
2 3 5 6
�������4�����̵�allocation��Դ�������
A B C D
0 0 3 2
�������4�����̵�need��Դ���
A B C D
0 6 5 2
�������5�����̵�allocation��Դ�������
A B C D
0 0 1 4
�������5�����̵�need��Դ���
A B C D
0 6 5 6
                                ���̸�����Դ���
==============================================================================================================
                  Max           Allocation                      Need
��Դ����| A     B       C       D|A     B       C       D|A     B       C       D
[����1] | 0     0       4       4 |0    0       3       2 |0    0       1       2
[����2] | 2     6       9       5 |1    0       0       0 |1    6       9       5
[����3] | 3     6       10      10 |1   3       5       4 |2    3       5       6
[����4] | 0     6       8       4 |0    0       3       2 |0    6       5       2
[����5] | 0     6       6       10 |0   0       1       4 |0    6       5       6

                                �м�����
                  Work                  Allocation              Need                    Work+Allocation
��Դ����| A     B       C       D|A     B       C       D|A     B       C       D|A     B       C       D
[����1] | 1     6       2       2 |0    0       3       2 |0    0       1       2 |1    6       5       4
[����2] | 1     6       9       10 |1   0       0       0 |1    6       9       5 |2    6       9       10
[����3] | 2     6       9       10 |1   3       5       4 |2    3       5       6 |3    9       14      14
[����4] | 1     6       5       4 |0    0       3       2 |0    6       5       2 |1    6       8       6
[����5] | 1     6       8       6 |0    0       1       4 |0    6       5       6 |1    6       9       10
==============================================================================================================
        ϵͳʣ����Դ��
        Available
A       B       C       D
1       6       2       2
���ڰ�ȫ����
��ȫ����Ϊ:1->4->5->2->3
�밴���������. . .
*/

/*
�������ϵͳ�Ľ�����:2
�������1�����̵�allocation��Դ�������
A B C D
2 6 13 13
�������1�����̵�need��Դ���
A B C D
1 1 1 1
�������2�����̵�allocation��Դ�������
A B C D
1 2 0 0
�������2�����̵�need��Դ���
A B C D
1 1 1 1
                                ���̸�����Դ���
==============================================================================================================
                  Max                                   Allocation                              Need
��Դ����| A     B       C       D       |       A       B       C       D       |       A       B       C       D
[����1] | 3     7       14      14      |       2       6       13      13      |       1       1       1       1
[����2] | 2     3       1       1       |       1       2       0       0       |       1       1       1       1
==============================================================================================================
        ϵͳʣ����Դ��
        Available
A       B       C       D
0       1       1       1
�����ڰ�ȫ����
�밴���������. . .
*/