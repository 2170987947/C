#include<stdio.h>
//字符串左旋
/*实现一个函数，可以左旋字符串中的k个字符。
例如：
ABCD左旋一个字符得到BCDA
ABCD左旋两个字符得到CDAB*/
void leftRotate(int* a,int num){
	while (num>0){
		//相互交换
		for (; *a != '\0'; a++){

		}
		num--;
	}
}

int main()
{
	char a[] = "Hello";
	//表示左旋多少个字符
	int num;
	printf("请输入左旋字符的个数:");
	scanf("%d", &num);
	//定义函数指针类型为Ptr
	typedef void(*Ptr)(int,int);
	//定义函数指针类型的变量
	Ptr point;
	//调用
	point(a,num);   
	system("pause");
	return 0;
}







//字符串旋转结果
/*写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。 
例如：给定s1 =AABCD和s2 = BCDAA，返回1

给定s1=abcd和s2=ACBD，返回0.



AABCD左旋一个字符得到ABCDA

AABCD左旋两个字符得到BCDAA

AABCD右旋一个字符得到DAABC*/