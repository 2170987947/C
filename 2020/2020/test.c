#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//字符串旋转
//循环实现
char* leftReverse1(char* str, int num){
	for (int i = 0; i < num; i++){
		char temp = *str;
		for (int j = 0; j < (int)strlen(str) - 1; j++){
			str[j] = str[j + 1];
		}
		str[strlen(str) - 1] = temp;
	}
	return str;
}
char* leftReverse2(char* str, int num){
	char temp[1024] = { 0 };
	strcpy(temp, str);
	strcat(temp, str);
	char temp1[1024] = { 0 };
	strncpy(str, (temp + 2), 5);
	return str;
}
int main()
{
	char str[] = "Hello";
	//printf("%s\n",leftReverse1(str, 2));
	printf("%s\n",leftReverse2(str, 2));
	system("pause");
	return 0;
}