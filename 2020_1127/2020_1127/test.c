#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//���׼�����
int add(int a, int b){
	return a + b;
}
int sub(int a, int b){
	return a - b;
}
int mul(int a, int b){
	return a*b;
}
int divi(int a, int b){
	if (b != 0){
		return a / b;
	}
	else{
		printf("��������Ϊ0\n");
		return 0;
	}
}
//����һ������ָ������fun
typedef int(*fun)(int, int);
int main()
{
	//ת�Ʊ�
	fun fun1[5] = {
		NULL, add, sub, mul, divi
	};
	int a = 0,b = 0;
	printf("��������������:");
	scanf("%d %d", &a, &b);
	int input = 1;
	printf("1.���\n");
	printf("2.���\n");
	printf("3.���\n");
	printf("4.���\n");
	printf("����������ѡ��:");
	scanf("%d", &input);
	if (input > 0 && input <= 4){
		if (b == 0&&input==4){
			printf("��������Ϊ0\n");
		}
		else{
			printf("%d\n", fun1[input](a, b));
		}
	}
	system("pause");
	return 0;
}