#include<stdio.h>
#include<stdlib.h>
int cmp(const int* a,const int* b){
	//��������
	return (*a - *b);
	//��������
	//return (*b- *a);
}
void print(int* a,int size){
	for (int i = 0; i < size; i++){
		printf("%d\t", a[i]);
	}
	printf("\n");
}
int main()
{
	int a[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	printf("ԭ����Ϊ:");
	print(a, sizeof(a)/sizeof(int));
	qsort(a, sizeof(a) / sizeof(int), sizeof(int), cmp);
	printf("����������Ϊ:");
	print(a, sizeof(a) / sizeof(int));
	system("pause");
	return 0;
}