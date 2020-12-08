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
	//�������ĸ�����Դ
	Resource request;
	//�ý��̵ı�־λ.��ʾ�ý����Ƿ��Ѿ�������
	int finish;
}Process;

//��һ�����������̵���Ϣ
typedef struct AllProcess{
	//ϵͳ�и�����Դ����
	Resource resourse_MAX;
	//�������̱������н���ռ����Դ(���ѷ�����Դ)���ܺ�
	Resource total_resourse;
	//��������
	Process process[PROCESS_MAX];
	//ϵͳ��ʣ����Դ��
	Resource available;
	//ϵͳ����Ч������
	int size;
	//��ȫ���к� (��0��ʼ)
	int array[PROCESS_MAX];
}AllProcess;

//��ÿ��������Ŀ�������Դ����max
void maxProcess(AllProcess* allProcess){
	Process* p = allProcess->process;
	//��ÿ�����̵ĸ�����Դ�������
	for (int i = 0; i < allProcess->size; i++){
		p[i].max.a = p[i].allocation.a + p[i].need.a;
		p[i].max.b = p[i].allocation.b + p[i].need.b;
		p[i].max.c = p[i].allocation.c + p[i].need.c;
		p[i].max.d = p[i].allocation.d + p[i].need.d;
	}
}
//��ϵͳ��ʣ����Դ��
void remainResource(AllProcess* allProcess){
	//��ָ��***
	//��С��û��ָ�뾹Ȼûд��ȥ
	Resource* ava = &allProcess->available;
	Resource* MAX = &allProcess->resourse_MAX;
	Resource* total = &allProcess->total_resourse;
	ava->a = MAX->a - total->a;
	ava->b = MAX->b - total->b;
	ava->c = MAX->c - total->c;
	ava->d = MAX->d - total->d;
}
//���������̱������н���ռ����Դ(���ѷ�����Դ)���ܺ�
void totalResource(AllProcess* allProcess){
	Process* p = allProcess->process;
	//��ָ��***
	Resource* total = &allProcess->total_resourse;
	total->a = 0;
	total->b = 0;
	total->c = 0;
	total->d = 0;
	//�Ƚ�ÿ�����̵�a����Դȫ����������
	for (int i = 0; i < allProcess->size; i++){
		total->a += p[i].allocation.a;
		total->b += p[i].allocation.b;
		total->c += p[i].allocation.c;
		total->d += p[i].allocation.d;

	}
}

//�Խ��̵ĸ�����Դ���г�ʼ��(need,allocation)
//���Ҷ�ϵͳ���ܵĸ�����Դ����ʼ��
//��ÿ�����̵ĸ�����Դ�������
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

		//ÿ�����̵ı�־λ��Ϊ0,��ʾ����δ������
		p[i].finish = 0;
	}
	totalResource(allProcess);

	//��ϵͳ����Դ��ʼ��
	//ͬʱ������Դ����У��:�ܵ���Դ��������ڵ��ڽ����ѷ�����Դ������
	//�����ϵͳ����Դ��ʼ��ʧ��
	Resource* MAX = &allProcess->resourse_MAX;
	Resource* total = &allProcess->total_resourse;
	while (1){
		printf("����ϵͳA,B,C,D��Դ����:");
		/*scanf("%d %d %d %d", &allProcess->resourse_MAX.a, &allProcess->resourse_MAX.b,
		&allProcess->resourse_MAX.c, &allProcess->resourse_MAX.d);*/
		scanf("%d %d %d %d", &MAX->a, &MAX->b, &MAX->c, &MAX->d);
		if (MAX->a >= total->a&&MAX->b >= total->b&&MAX->c >= total->c&&MAX->d >= total->d){
			break;
		}else{
			printf("�������ϵͳ�еĸ�����Դ��������,����������ϵͳA,B,C,D��Դ����:");
			continue;
		}
	}
	remainResource(allProcess);
	maxProcess(allProcess);
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
//���м��㷨
void Bankers(AllProcess* allProcess){
	initAllProcess(allProcess);
	remainResource(allProcess);
	//�������ĸ��������������Դ( Ϊ���,���±�)
	int num = 0;
	//������Ľ��̽���У��:���ý����Ƿ���ڸý���
	//����:�˼ҽ�������5,��ȴ˵����6��������Դ
	printf("�����ĸ��������������Դ[1,%d]:",allProcess->size);
	while (1){
		scanf("%d", &num);
		if (num <= allProcess->size && num >= 1){
			break;
		}else{
			printf("������Ϸ��Ľ��̺�[1,%d]:", allProcess->size);
			continue;
		}
	}
	//�����������Դ��Ŀ
	printf("������[%d����]����Դ����(A,B,C,D):",num);
	//ĳ�Ž�������ĸ�����Դ
	Resource* r = &allProcess->process[num - 1].request;
	/*scanf("%d %d %d %d", &allProcess->process[num - 1].request.a,
		&allProcess->process[num - 1].request.b, &allProcess->process[num - 1].request.c,
		&allProcess->process[num - 1].request.d);*/
	scanf("%d %d %d %d", &r->a, &r->b, &r->c, &r->d);
	//ĳ�Ž�����Ҫ�ĸ�����Դ
	Resource* n = &allProcess->process[num - 1].need;
	//ĳ�Ž����ѷ���ĸ�����Դ
	Resource* all = &allProcess->process[num - 1].allocation;
	
	if (r->a <= n->a&&r->b <= n->b&&r->c <= n->c&&r->d <= n->d
		&&r->a<=allProcess->available.a&&r->b<=allProcess->available.b
		&&r->c<=allProcess->available.c&&r->d<=allProcess->available.d){
		//���¸ý��̵��ѷ�����Դ
		all->a += r->a;
		all->b += r->b;
		all->c += r->c;
		all->d += r->d;
		//���¸ý��̵���Ҫ��Դ
		n->a -= r->a;
		n->b -= r->b;
		n->c -= r->c;
		n->d -= r->d;
		
		//���������µ�����ϵͳ����ʣ��Դ��
		allProcess->available.a -= r->a;
		allProcess->available.b -= r->b;
		allProcess->available.c -= r->c;
		allProcess->available.d -= r->d;

		if (isSecureArray(allProcess) == 1){
			printf("���ڰ�ȫ����\n");
			printf("��ȫ����Ϊ:");
			for (int i = 0; i < allProcess->size; i++){
				//��������һ�����,�Ͳ���->
				if (i == allProcess->size - 1){
					printf("%d\n", allProcess->array[i] + 1);
				}
				else{
					printf("%d->", allProcess->array[i] + 1);
				}
			}
		}
		else{
			printf("�����ڰ�ȫ����\n");
		}
	} else{
		printf("����ʧ��,�����ڰ�ȫ����\n");
		return;
	}

}
//����ָ�����͵�����ϵͳ
AllProcess allProcess;

int main()
{
	Bankers(&allProcess);
	system("pause");
	return 0;
}
//��������
/*
�������ϵͳ�Ľ�����:2
�������1�����̵�allocation��Դ�������
A B C D
1 1 1 1
�������1�����̵�need��Դ���
A B C D
1 2 3 4
�������2�����̵�allocation��Դ�������
A B C D
4 3 2 1
�������2�����̵�need��Դ���
A B C D
1 1 1 1
����ϵͳA,B,C,D��Դ����:5 5 5 5
�����ĸ��������������Դ[1,2]:2
������[2����]����Դ����(A,B,C,D):0 1 1 1
���̸�����Դ���
==============================================================================================================
Max           Allocation                      Need
��Դ����| A     B       C       D|A     B       C       D|A     B       C       D
[����1] | 2     3       4       5 |1    1       1       1 |1    2       3       4
[����2] | 5     4       3       2 |4    4       3       2 |1    0       0       0

�м�����
Work                  Allocation              Need                    Work+Allocation
��Դ����| A     B       C       D|A     B       C       D|A     B       C       D|A     B       C       D
[����1] | 0     0       0       0 |1    1       1       1 |1    2       3       4 |0    0       0       0
[����2] | 0     0       0       0 |4    4       3       2 |1    0       0       0 |0    0       0       0
==============================================================================================================
ϵͳʣ����Դ��
Available
A       B       C       D
0       0       1       2
�����ڰ�ȫ����
�밴���������. . .
*/
//��������2
/*
�������ϵͳ�Ľ�����:2
�������1�����̵�allocation��Դ�������
A B C D
4 3 2 1
�������1�����̵�need��Դ���
A B C D
1 1 1 1
�������2�����̵�allocation��Դ�������
A B C D
1 1 1 1
�������2�����̵�need��Դ���
A B C D
1 2 3 4
����ϵͳA,B,C,D��Դ����:6 6 6 6
�����ĸ��������������Դ;1
������[1����]����Դ����(A,B,C,D):1 1 1 1
                                ���̸�����Դ���
==============================================================================================================
                  Max           Allocation                      Need
��Դ����| A     B       C       D|A     B       C       D|A     B       C       D
[����1] | 5     4       3       2 |5    4       3       2 |0    0       0       0
[����2] | 2     3       4       5 |1    1       1       1 |1    2       3       4

                                �м�����
                  Work                  Allocation              Need                    Work+Allocation
��Դ����| A     B       C       D|A     B       C       D|A     B       C       D|A     B       C       D
[����1] | 0     1       2       3 |5    4       3       2 |0    0       0       0 |5    5       5       5
[����2] | 5     5       5       5 |1    1       1       1 |1    2       3       4 |6    6       6       6
==============================================================================================================
        ϵͳʣ����Դ��
        Available
A       B       C       D
0       1       2       3
���ڰ�ȫ����
��ȫ����Ϊ:1->2
�밴���������. . .
*/

