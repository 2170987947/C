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
	//请求分配的各类资源
	Resource request;
	//该进程的标志位.表示该进程是否已经被运行
	int finish;
}Process;

//另一个是整个进程的信息
typedef struct AllProcess{
	//系统中各类资源总数
	Resource resourse_MAX;
	//整个进程表中所有进程占用资源(即已分配资源)的总和
	Resource total_resourse;
	//进程数组
	Process process[PROCESS_MAX];
	//系统中剩余资源数
	Resource available;
	//系统中有效进程数
	int size;
	//安全序列号 (从0开始)
	int array[PROCESS_MAX];
}AllProcess;

//求每个进程条目的最大资源总数max
void maxProcess(AllProcess* allProcess){
	Process* p = allProcess->process;
	//求每个进程的各个资源的最大数
	for (int i = 0; i < allProcess->size; i++){
		p[i].max.a = p[i].allocation.a + p[i].need.a;
		p[i].max.b = p[i].allocation.b + p[i].need.b;
		p[i].max.c = p[i].allocation.c + p[i].need.c;
		p[i].max.d = p[i].allocation.d + p[i].need.d;
	}
}
//求系统中剩余资源数
void remainResource(AllProcess* allProcess){
	//用指针***
	//不小心没用指针竟然没写进去
	Resource* ava = &allProcess->available;
	Resource* MAX = &allProcess->resourse_MAX;
	Resource* total = &allProcess->total_resourse;
	ava->a = MAX->a - total->a;
	ava->b = MAX->b - total->b;
	ava->c = MAX->c - total->c;
	ava->d = MAX->d - total->d;
}
//求整个进程表中所有进程占用资源(即已分配资源)的总和
void totalResource(AllProcess* allProcess){
	Process* p = allProcess->process;
	//用指针***
	Resource* total = &allProcess->total_resourse;
	total->a = 0;
	total->b = 0;
	total->c = 0;
	total->d = 0;
	//先将每个进程的a类资源全部加起来放
	for (int i = 0; i < allProcess->size; i++){
		total->a += p[i].allocation.a;
		total->b += p[i].allocation.b;
		total->c += p[i].allocation.c;
		total->d += p[i].allocation.d;

	}
}

//对进程的各个资源进行初始化(need,allocation)
//并且对系统中总的各类资源数初始化
//求每个进程的各个资源的最大数
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

		//每个进程的标志位置为0,表示进程未被运行
		p[i].finish = 0;
	}
	totalResource(allProcess);

	//对系统总资源初始化
	//同时对总资源进行校验:总的资源数必须大于等于进程已分配资源的总数
	//否则对系统总资源初始化失败
	Resource* MAX = &allProcess->resourse_MAX;
	Resource* total = &allProcess->total_resourse;
	while (1){
		printf("输入系统A,B,C,D资源总数:");
		/*scanf("%d %d %d %d", &allProcess->resourse_MAX.a, &allProcess->resourse_MAX.b,
		&allProcess->resourse_MAX.c, &allProcess->resourse_MAX.d);*/
		scanf("%d %d %d %d", &MAX->a, &MAX->b, &MAX->c, &MAX->d);
		if (MAX->a >= total->a&&MAX->b >= total->b&&MAX->c >= total->c&&MAX->d >= total->d){
			break;
		}else{
			printf("您输入的系统中的各类资源总数有误,请重新输入系统A,B,C,D资源总数:");
			continue;
		}
	}
	remainResource(allProcess);
	maxProcess(allProcess);
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
//银行家算法
void Bankers(AllProcess* allProcess){
	initAllProcess(allProcess);
	remainResource(allProcess);
	//求输入哪个进程请求分配资源( 为标号,非下标)
	int num = 0;
	//对请求的进程进行校验:看该进程是否存在该进程
	//比如:人家进程数是5,你却说进程6在请求资源
	printf("输入哪个进程请求分配资源[1,%d]:",allProcess->size);
	while (1){
		scanf("%d", &num);
		if (num <= allProcess->size && num >= 1){
			break;
		}else{
			printf("请输入合法的进程号[1,%d]:", allProcess->size);
			continue;
		}
	}
	//输入请求的资源数目
	printf("请输入[%d进程]的资源请求(A,B,C,D):",num);
	//某号进程请求的各类资源
	Resource* r = &allProcess->process[num - 1].request;
	/*scanf("%d %d %d %d", &allProcess->process[num - 1].request.a,
		&allProcess->process[num - 1].request.b, &allProcess->process[num - 1].request.c,
		&allProcess->process[num - 1].request.d);*/
	scanf("%d %d %d %d", &r->a, &r->b, &r->c, &r->d);
	//某号进程需要的各类资源
	Resource* n = &allProcess->process[num - 1].need;
	//某号进程已分配的各类资源
	Resource* all = &allProcess->process[num - 1].allocation;
	
	if (r->a <= n->a&&r->b <= n->b&&r->c <= n->c&&r->d <= n->d
		&&r->a<=allProcess->available.a&&r->b<=allProcess->available.b
		&&r->c<=allProcess->available.c&&r->d<=allProcess->available.d){
		//更新该进程的已分配资源
		all->a += r->a;
		all->b += r->b;
		all->c += r->c;
		all->d += r->d;
		//更新该进程的需要资源
		n->a -= r->a;
		n->b -= r->b;
		n->c -= r->c;
		n->d -= r->d;
		
		//更新由于新的请求系统中所剩资源数
		allProcess->available.a -= r->a;
		allProcess->available.b -= r->b;
		allProcess->available.c -= r->c;
		allProcess->available.d -= r->d;

		if (isSecureArray(allProcess) == 1){
			printf("存在安全序列\n");
			printf("安全序列为:");
			for (int i = 0; i < allProcess->size; i++){
				//如果是最后一个输出,就不带->
				if (i == allProcess->size - 1){
					printf("%d\n", allProcess->array[i] + 1);
				}
				else{
					printf("%d->", allProcess->array[i] + 1);
				}
			}
		}
		else{
			printf("不存在安全序列\n");
		}
	} else{
		printf("请求失败,不存在安全序列\n");
		return;
	}

}
//定义指针类型的整个系统
AllProcess allProcess;

int main()
{
	Bankers(&allProcess);
	system("pause");
	return 0;
}
//测试用例
/*
请输入该系统的进程数:2
请输入第1个进程的allocation资源分配情况
A B C D
1 1 1 1
请输入第1个进程的need资源情况
A B C D
1 2 3 4
请输入第2个进程的allocation资源分配情况
A B C D
4 3 2 1
请输入第2个进程的need资源情况
A B C D
1 1 1 1
输入系统A,B,C,D资源总数:5 5 5 5
输入哪个进程请求分配资源[1,2]:2
请输入[2进程]的资源请求(A,B,C,D):0 1 1 1
进程各类资源表格
==============================================================================================================
Max           Allocation                      Need
资源名称| A     B       C       D|A     B       C       D|A     B       C       D
[进程1] | 2     3       4       5 |1    1       1       1 |1    2       3       4
[进程2] | 5     4       3       2 |4    4       3       2 |1    0       0       0

中间运算
Work                  Allocation              Need                    Work+Allocation
资源名称| A     B       C       D|A     B       C       D|A     B       C       D|A     B       C       D
[进程1] | 0     0       0       0 |1    1       1       1 |1    2       3       4 |0    0       0       0
[进程2] | 0     0       0       0 |4    4       3       2 |1    0       0       0 |0    0       0       0
==============================================================================================================
系统剩余资源数
Available
A       B       C       D
0       0       1       2
不存在安全序列
请按任意键继续. . .
*/
//测试用例2
/*
请输入该系统的进程数:2
请输入第1个进程的allocation资源分配情况
A B C D
4 3 2 1
请输入第1个进程的need资源情况
A B C D
1 1 1 1
请输入第2个进程的allocation资源分配情况
A B C D
1 1 1 1
请输入第2个进程的need资源情况
A B C D
1 2 3 4
输入系统A,B,C,D资源总数:6 6 6 6
输入哪个进程请求分配资源;1
请输入[1进程]的资源请求(A,B,C,D):1 1 1 1
                                进程各类资源表格
==============================================================================================================
                  Max           Allocation                      Need
资源名称| A     B       C       D|A     B       C       D|A     B       C       D
[进程1] | 5     4       3       2 |5    4       3       2 |0    0       0       0
[进程2] | 2     3       4       5 |1    1       1       1 |1    2       3       4

                                中间运算
                  Work                  Allocation              Need                    Work+Allocation
资源名称| A     B       C       D|A     B       C       D|A     B       C       D|A     B       C       D
[进程1] | 0     1       2       3 |5    4       3       2 |0    0       0       0 |5    5       5       5
[进程2] | 5     5       5       5 |1    1       1       1 |1    2       3       4 |6    6       6       6
==============================================================================================================
        系统剩余资源数
        Available
A       B       C       D
0       1       2       3
存在安全序列
安全序列为:1->2
请按任意键继续. . .
*/

