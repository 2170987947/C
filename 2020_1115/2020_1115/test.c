///字符串旋转结果
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//字符串旋转结果
/*题目内容：
写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。

例如：给定s1 = AABCD和s2 = BCDAA，返回1

给定s1 = abcd和s2 = ACBD，返回0.

AABCD左旋一个字符得到ABCDA

AABCD左旋两个字符得到BCDAA

AABCD右旋一个字符得到DAAB
*/
//左移
int leftRotate(char str[], int length,char str1[]){
	char* a = str;
	char temp = 0;
	for (int i = 1; i <= length; i++){
		//将字符串第一个字符暂时存入temp.
		temp = *a;
		for (; a + 1 < a+strlen(a); a++){
			*a = *(a + 1);
		}
		//给最后一个字符('\0'前一个元素)赋值.
		*a = temp;
		//将数组最开始的指针赋值给a.
		a = str;
		//printf("%s和%s是可以相互旋转的\n", str, str1);
		if (strcmp(str, str1) == 0){
			printf("是可以相互旋转的\n", str, str1);
			return 1;
		}
	}
	printf("不是旋转后的结果\n");
	return 0;
}
int main()
{
	char str[] = "ABCD";
	char str1[] = "CDAB";
	printf("%s和%s\n", str, str1);
	int ret=leftRotate(str, strlen(str),  str1);
	printf("%d\n", ret);
	system("pause");
	return 0;
}

////猜名次
/*#include<stdio.h>
#define PLAYER 5
/*猜名次

作业内容
5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：

A选手说：B第二，我第三；

B选手说：我第二，E第四；

C选手说：我第一，D第二；

D选手说：C最后，我第三；

E选手说：我第四，A第一；

比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
void sort(){
	for (int a = 1; a <= PLAYER; a++){
		for (int b = 1; b <= PLAYER; b++){
			for (int c = 1; c < PLAYER; c++){
				for (int d = 1; d < PLAYER; d++){
					for (int e = 1; e < PLAYER; e++){
						if (a*b*c*d*e == 120){
							if ((a == 3 && b != 2) || (a != 3 || b == 2)){
								if ((b == 2 && e != 4) || (b != 2 && e == 4)){
									if ((c == 1 && d != 2) || (c != 1 && d == 2)){
										if ((c == 4 && d != 3) || (c != 4 && d == 3)){
											if ((e == 4 && a != 1) || (a != 4 && a == 1)){
												printf("名次为%d %d %d %d %d\n", a, b, c, d, e);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
int main()
{
	//int a[PLAYER][PLAYER] = { 0 };
	sort();
	system("pause");
	return 0;
}
*/