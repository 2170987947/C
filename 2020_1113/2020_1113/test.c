#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//�ַ�������
/*ʵ��һ�����������������ַ����е�k���ַ���
���磺
ABCD����һ���ַ��õ�BCDA
ABCD���������ַ��õ�CDAB*/
void leftRotate(char* str,int num){
	while (num>0){
		char* a = str;
		char temp = *str;
		for (; *(a+1) != '\0'; a++){
			*a=*(a+1);
		}
		*a = temp;
		num--;
	}
}

int main()
{
	char a[] = "ABCD";
	//��ʾ�������ٸ��ַ�
	int num;
	printf("�����������ַ��ĸ���:");
	scanf("%d", &num);
	leftRotate(a, num);
	printf("%s\n", a);
	//���庯��ָ������ΪPtr
	/*typedef void(*Ptr)(char*,int);
	//���庯��ָ�����͵ı���
	Ptr point;
	//����
	point(a,num);   */
	system("pause");
	return 0;
}







//�ַ�����ת���
/*дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ����� 
���磺����s1 =AABCD��s2 = BCDAA������1

����s1=abcd��s2=ACBD������0.



AABCD����һ���ַ��õ�ABCDA

AABCD���������ַ��õ�BCDAA

AABCD����һ���ַ��õ�DAABC*/