#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//简易计算器
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
		printf("除数不能为0\n");
		return 0;
	}
}
//定义一个函数指针类型fun
typedef int(*fun)(int, int);
int main()
{
	//转移表
	fun fun1[5] = {
		NULL, add, sub, mul, divi
	};
	int a = 0,b = 0;
	printf("请输入两个整数:");
	scanf("%d %d", &a, &b);
	int input = 1;
	printf("1.相加\n");
	printf("2.相减\n");
	printf("3.相乘\n");
	printf("4.相除\n");
	printf("请输入您的选择:");
	scanf("%d", &input);
	if (input > 0 && input <= 4){
		if (b == 0&&input==4){
			printf("除数不能为0\n");
		}
		else{
			printf("%d\n", fun1[input](a, b));
		}
	}
	system("pause");
	return 0;
}