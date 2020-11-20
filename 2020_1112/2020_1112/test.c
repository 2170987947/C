///判断大小端
#include<stdio.h>
#include<stdlib.h>
//核心思想:取出int的最低地址对应的一个字节,看其存放的是高位还是低位.
//如果是大端,返回1
//如果是小端,返回0;
int isBigEnd(int num){
	int* p = &num;
	char* p2 = (char*)p;
	//如果存放的是11(高位)
	if (*p2==0x11){
		return 1;
	}
	return 0;
}
int main()
{
	int num = 0x11223344;
	printf("返回1表示大端\n返回0表示小端\n");
	printf("%d\n", isBigEnd(num));
	system("pause");
	return 0;
}