
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//整形
int cmp1(const void *a, const void *b){
	assert(a);
	assert(b);
	return (*(int *)a - *(int *)b);
}
//双精度浮点型
int cmp2(const void* a, const void* b){
	assert(a);
	assert(b);
	return(*(double*)a - *(double*)b)>0 ? 1 : -1;
}
//字符串类型
int cmp3(const void* a, const void* b){
	assert(a);
	assert(b);
	return (*(char*)a - *(char*)b);
}
//指针数组
int cmp4(const void* a, const void* b){
	assert(a);
	assert(b);
	return strcmp((char*)*(int*)a, (char*)*(int*)b);
}
int main()
{
	int i = 0;
	int a[] = { 1, 3, 4, 5, 8, 0, 9, 7, 2, 6 };//一维数组
	double b[] = { 1.0, 4.0, 2.0, 3.0 };
	char c[] = "BADC";
	char* d[3] = { "acd", "adc", "aaa" };
	qsort(a, sizeof(a)/sizeof(int), sizeof(int), cmp1);
	qsort(b, sizeof(b)/sizeof(double), sizeof(double), cmp2);
	qsort(c, strlen(c), sizeof(char), cmp3);
	qsort(d, 3, sizeof(char*), cmp4);
	for (i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	
	
	for (i = 0; i < sizeof(b) / sizeof(double); i++)
	{
		printf("%f ", b[i]);
	}
	printf("\n");
	
	for (i = 0; i < strlen(c); i++)
	{
		printf("%c ", c[i]);
	}
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		printf("%s ", d[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}


//#include<stdio.h>
//#include<stdlib.h>
//typedef int(*compar)(int a, int b);
///*qsort使用练习
//题目内容：
//练习使用库函数，qsort排序各种类型的数据*/
//void qSort(int* base, int num, compar com){
//	for (int bound = 0; bound < num; bound++){
//		for (int cur=num-1; cur > bound; cur--){
//			if (com( base[cur-1],base[cur] ) == 1){
//				int temp = base[cur - 1];
//				base[cur-1]=base[cur];
//				base[cur] = temp;
//			}
//		}
//	}
//}
//int compare( int a, int b){
//	if ( a==b){
//		return 0;
//	}
//	if (a<b){
//		return -1;
//	}
//	return 1;
//
//}
//int main()
//{
//	int arr[] = { 2, 1, 4, 7, 9, 5 };
//	qSort(arr, sizeof(arr) / sizeof(int), compare);
//	for (int i = 0; i < sizeof(arr) / sizeof(int); i++){
//		printf("%d\n", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

///qsort模拟实现
//模仿qsort的功能实现一个通用的冒泡排序
//排序
//void bubbleSort1(int arr[], int size, int asc){
//	for (int bound = 0; bound < size; bound++){
//		for (int i = size - 1; i>bound; i--){
//			if (asc == 1){
//				if (arr[i] < arr[i - 1]){
//					int temp = arr[i];
//					arr[i] = arr[i - 1];
//					arr[i - 1] = temp;
//				}
//			}
//			if (asc == 0){
//				if (arr[i]>arr[i - 1]){
//					int temp = arr[i];
//					arr[i] = arr[i - 1];
//					arr[i - 1] = temp;
//				}
//			}
//		}
//	}
//}
//
//
//typedef int(*Cmp)(int a, int b);
////通用排序
//
//void bubbleSort2(int arr[], int size, Cmp cmp){
//	for (int bound = 0; bound < size; bound++){
//		for (int cur = size - 1; cur > bound; cur--){
//			if (cmp(arr[cur - 1], arr[cur]) == 1){
//				int temp = arr[cur];
//				arr[cur] = arr[cur - 1];
//				arr[cur - 1] = temp;
//			}
//		}
//	}
//}
//int less(int a, int b){
//	if (a == b){
//		return 0;
//	}
//	if (a < b){
//		return -1;
//	}
//	return 1;
//}
//
//int main()
//{
//	void bubbleSort2(int arr[], int size, Cmp cmp);
//	int arr[] = { 1, 6, 2, 9 };
//	bubbleSort1(arr, sizeof(arr) / sizeof(int), 0);
//	bubbleSort2(arr, sizeof(arr) / sizeof(int), less);
//	for (int i = 0; i < sizeof(arr) / sizeof(int); i++){
//		printf("%d\t", arr[i]);
//	}
//	system("pause");
//	return 0;
//}
