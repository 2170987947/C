#include<stdio.h>
#include <stdlib.h>
//字符串旋转结果
/*写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。

例如：给定s1 = AABCD和s2 = BCDAA，返回1

给定s1 = abcd和s2 = ACBD，返回0.

AABCD左旋一个字符得到ABCDA

AABCD左旋两个字符得到BCDAA

AABCD右旋一个字符得到DAABC
*/
int isRotate(char* a, char* b){
	char* str = a;
	char temp = 0;
	for (int i = 1; i <= 4;i++){
		temp = *str;
		for (; str + 1 < str + strlen(str);str++){
			*str = *(str + 1);

		}
		*str = temp;
		str = a;
		printf("%s\n", a);
	}

	return 0;
}
int main()
{
	char a[] = "ABCD";
	char b[] = "BCDE";
	isRotate(a, b);
	system("pause");
	return 0;
}