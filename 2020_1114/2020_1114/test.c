#include<stdio.h>
#include <stdlib.h>
//�ַ�����ת���
/*дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����

���磺����s1 = AABCD��s2 = BCDAA������1

����s1 = abcd��s2 = ACBD������0.

AABCD����һ���ַ��õ�ABCDA

AABCD���������ַ��õ�BCDAA

AABCD����һ���ַ��õ�DAABC
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