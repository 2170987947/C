#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define PROCESS_MAX 10
//资源种类
#define RESOURCE_KIND 4
//系统中的各类资源总数
#define A_MAX 3
#define B_MAX 9
#define C_MAX 14
#define D_MAX 14
//建立三个结构体

//一个是资源的分类
typedef struct Resource{
	int a;
	int b;
	int c;
	int d;
}Resource;

//一个是进程的信息
typedef struct Process{
	//单个进程
	//最大资源数
	Resource max;
	//已分配资源数
	Resource allocation;
	//所需资源数
	Resource need;
	//可工作的资源数
	Resource work;
	//可工作的和已分配的资源总和
	//实际上就是该进程运行完系统中可使用的资源数
	Resource work_allocation;
	//该进程的标志位.表示该进程是否已经被运行
	int finish;
}Process;

//另一个是整个进程的信息
typedef struct AllProcess{
	Process process[PROCESS_MAX];
	//系统中剩余资源数
	Resource available;
	//系统中有效进程数
	int size;
	//安全序列号 (从0开始)
	int array[PROCESS_MAX];
}AllProcess;

//对进程的各个资源进行初始化
void initAllProcess(AllProcess* allProcess){
	printf("请输入该系统的进程数:");
	scanf("%d", &allProcess->size);
	Process* p = allProcess->process;
	for (int i = 0; i < allProcess->size; i++){
		printf("请输入第%d个进程的allocation资源分配情况\n", i+1);
		printf("A B C D\n");
		scanf("%d %d %d %d",
		&p[i].allocation.a,
		&p[i].allocation.b,
		&p[i].allocation.c,
		&p[i].allocation.d);

		printf("请输入第%d个进程的need资源情况\n", i+1);
		printf("A B C D\n");
		scanf("%d %d %d %d",&p[i].need.a,&p[i].need.b,
			&p[i].need.c,&p[i].need.d);

		//求每个进程的各个资源的最大数
		p[i].max.a = p[i].allocation.a + p[i].need.a;
		p[i].max.b = p[i].allocation.b + p[i].need.b;
		p[i].max.c = p[i].allocation.c + p[i].need.c;
		      p[i].max.d = p[i].allocation.d + p[i].need.d;

		//每个进程的标志位置为0,表示进程未被运行
		p[i].finish = 0;
	}
	
}

//求系统中剩余资源数
void remainResource(AllProcess* allProcess){
	//for (int kind = 0; kind < RESOURCE_KIND; kind++){
	Process* p=allProcess->process;
	//用指针***
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

//某进程请求资源,系统是否分配给它
//打印进程各个资源的信息
void print(AllProcess* allProcess){
	Process* p = allProcess->process;
	printf("\t\t\t\t进程各类资源表格\n");
	printf("==============================================================================================================\n");
	printf("      \t\t  Max\t\tAllocation\t\t\tNeed\n");
	printf("资源名称| A\tB\tC\tD|A\tB\tC\tD|A\tB\tC\tD\n");

	for (int i = 0; i < allProcess->size; i++){
		printf("[进程%d]\t| %d\t%d\t%d\t%d |", i + 1,
			p[i].max.a, p[i].max.b, p[i].max.c, p[i].max.d);

		printf("%d\t%d\t%d\t%d |",
			p[i].allocation.a, p[i].allocation.b,
			p[i].allocation.c, p[i].allocation.d);

		printf("%d\t%d\t%d\t%d\n",
			p[i].need.a, p[i].need.b, p[i].need.c, p[i].need.d);
	}
	printf("\n");

	printf("\t\t\t\t中间运算\n");
	printf("      \t\t  Work\t\t\tAllocation\t\tNeed\t\t\tWork+Allocation\n");
	printf("资源名称| A\tB\tC\tD|A\tB\tC\tD|A\tB\tC\tD|A\tB\tC\tD\t\n");

	for (int i = 0; i < allProcess->size; i++){
		printf("[进程%d]\t| %d\t%d\t%d\t%d |", i + 1,
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
	//整个系统剩余资源数
	printf("\t系统剩余资源数\n");
	printf("\tAvailable\n");

	printf("A\tB\tC\tD\n");
	printf("%d\t%d\t%d\t%d\n",
		allProcess->available.a, allProcess->available.b,
		allProcess->available.c, allProcess->available.d);
}

//是否存在安全序列
//存在返回1
//不存在返回0
int isSecureArray(AllProcess* allProcess){
	Process* p = allProcess->process;
	//安全序列好的下标
	int count = 0;
	//先判断从哪个进程开始,然后将系统中剩余资源是分配给它.
	for (int i = 0; i<allProcess->size; i++){
		//若系统中剩余资源数大于等于其某个进程需要的资源数,就运行它
		if (allProcess->available.a>=p[i].need.a
			&&allProcess->available.b >= p[i].need.b
			&&allProcess->available.c >= p[i].need.c
			&&allProcess->available.d >= p[i].need.d){	

			//可工作的资源(试分配)初始化work
			(p+i)->work.a = allProcess->available.a;
			p[i].work.b = allProcess->available.b;
			p[i].work.c = allProcess->available.c;
			p[i].work.d = allProcess->available.d;

			//运行该进程,将其标志位置为1.
			p[i].finish = 1;
			//将第i进程写入安全序列号中
			allProcess->array[count++] = i;

			//释放该进程后,系统中可工作的资源work-allocation
			p[i].work_allocation.a = p[i].work.a + p[i].allocation.a;
			p[i].work_allocation.b = p[i].work.b + p[i].allocation.b;
			p[i].work_allocation.c = p[i].work.c + p[i].allocation.c;
			p[i].work_allocation.d = p[i].work.d + p[i].allocation.d;
			
			//找到第一个序列,即开始序列,则跳出循环
			break;
		}
		
	}
	//记录安全序列有没有新增
	int count1 = 0;
	
	//1. 当安全序列数组已满时,即count超过数组下标时
	//2. 或者因资源不够,系统中进程不能够全部运行
	//循环结束
	while (count<allProcess->size && count1!=count){
		//当整个for循环完count1==count
		//表明检索了整个进程表都没有可以运行的进程
		//说明不存在安全序列
	
		//如果发生了变化,则把发生变化后的值赋给count1
		//以方便后续判断其是否发生变化
		count1 = count;
		for (int i = 0; i<allProcess->size; i++){

			//当标志位不为0,且刚刚释放的资源数大于等于其某个进程需要的资源数,就运行它
			if (p[i].finish!=1
				&&p[allProcess->array[count - 1]].work_allocation.a >= p[i].need.a
				&&p[allProcess->array[count - 1]].work_allocation.b >= p[i].need.b
				&&p[allProcess->array[count - 1]].work_allocation.c >= p[i].need.c
				&&p[allProcess->array[count - 1]].work_allocation.d >= p[i].need.d){

				//系统可为该进程可工作的资源
				//即刚刚运行完毕所进程释放的资源
				p[i].work.a = p[allProcess->array[count - 1]].work_allocation.a;
				p[i].work.b = p[allProcess->array[count - 1]].work_allocation.b;
				p[i].work.c = p[allProcess->array[count - 1]].work_allocation.c;
				p[i].work.d = p[allProcess->array[count - 1]].work_allocation.d;

				//运行该进程,将其标志位置为1.
				allProcess->process[i].finish = 1;
				//将第i进程写入安全序列号中
				allProcess->array[count++] = i;

				//释放该进程后,系统中可工作的资源work-allocation
				p[i].work_allocation.a = p[i].work.a + p[i].allocation.a;
				p[i].work_allocation.b = p[i].work.b + p[i].allocation.b;
				p[i].work_allocation.c = p[i].work.c + p[i].allocation.c;
				p[i].work_allocation.d = p[i].work.d + p[i].allocation.d;
			}
		}
	}
	print(allProcess);
	//返回1 代表存在安全序列
	if (count >= allProcess->size){
		return 1;
	}
	return 0;
}

//定义指针类型的整个系统
AllProcess allProcess;

int main()
{
	initAllProcess(&allProcess);
	remainResource(&allProcess);

	if (isSecureArray(&allProcess) == 1){
		printf("存在安全序列\n");
		printf("安全序列为:");
		for (int i = 0; i < allProcess.size; i++){
			//如果是最后一个输出,就不带->
			if (i == allProcess.size - 1){
				printf("%d\n", allProcess.array[i] + 1);
			}else{
				printf("%d->", allProcess.array[i] + 1);
			}
		}
	}else{
		printf("不存在安全序列\n");
	}
	system("pause");
	return 0;
}
/*
请输入该系统的进程数:5
请输入第1个进程的allocation资源分配情况
A B C D
0 0 3 2
请输入第1个进程的need资源情况
A B C D
0 0 1 2
请输入第2个进程的allocation资源分配情况
A B C D
1 0 0 0
请输入第2个进程的need资源情况
A B C D
1 6 9 5
请输入第3个进程的allocation资源分配情况
A B C D
1 3 5 4
请输入第3个进程的need资源情况
A B C D
2 3 5 6
请输入第4个进程的allocation资源分配情况
A B C D
0 0 3 2
请输入第4个进程的need资源情况
A B C D
0 6 5 2
请输入第5个进程的allocation资源分配情况
A B C D
0 0 1 4
请输入第5个进程的need资源情况
A B C D
0 6 5 6
                                进程各类资源表格
==============================================================================================================
                  Max           Allocation                      Need
资源名称| A     B       C       D|A     B       C       D|A     B       C       D
[进程1] | 0     0       4       4 |0    0       3       2 |0    0       1       2
[进程2] | 2     6       9       5 |1    0       0       0 |1    6       9       5
[进程3] | 3     6       10      10 |1   3       5       4 |2    3       5       6
[进程4] | 0     6       8       4 |0    0       3       2 |0    6       5       2
[进程5] | 0     6       6       10 |0   0       1       4 |0    6       5       6

                                中间运算
                  Work                  Allocation              Need                    Work+Allocation
资源名称| A     B       C       D|A     B       C       D|A     B       C       D|A     B       C       D
[进程1] | 1     6       2       2 |0    0       3       2 |0    0       1       2 |1    6       5       4
[进程2] | 1     6       9       10 |1   0       0       0 |1    6       9       5 |2    6       9       10
[进程3] | 2     6       9       10 |1   3       5       4 |2    3       5       6 |3    9       14      14
[进程4] | 1     6       5       4 |0    0       3       2 |0    6       5       2 |1    6       8       6
[进程5] | 1     6       8       6 |0    0       1       4 |0    6       5       6 |1    6       9       10
==============================================================================================================
        系统剩余资源数
        Available
A       B       C       D
1       6       2       2
存在安全序列
安全序列为:1->4->5->2->3
请按任意键继续. . .
*/

/*
请输入该系统的进程数:2
请输入第1个进程的allocation资源分配情况
A B C D
2 6 13 13
请输入第1个进程的need资源情况
A B C D
1 1 1 1
请输入第2个进程的allocation资源分配情况
A B C D
1 2 0 0
请输入第2个进程的need资源情况
A B C D
1 1 1 1
                                进程各类资源表格
==============================================================================================================
                  Max                                   Allocation                              Need
资源名称| A     B       C       D       |       A       B       C       D       |       A       B       C       D
[进程1] | 3     7       14      14      |       2       6       13      13      |       1       1       1       1
[进程2] | 2     3       1       1       |       1       2       0       0       |       1       1       1       1
==============================================================================================================
        系统剩余资源数
        Available
A       B       C       D
0       1       1       1
不存在安全序列
请按任意键继续. . .
*/