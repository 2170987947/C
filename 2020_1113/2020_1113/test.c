#include<stdio.h>
//�ַ�������
/*ʵ��һ�����������������ַ����е�k���ַ���
���磺
ABCD����һ���ַ��õ�BCDA
ABCD���������ַ��õ�CDAB*/
void leftRotate(int* a,int num){
	while (num>0){
		//�໥����
		for (; *a != '\0'; a++){

		}
		num--;
	}
}

int main()
{
	char a[] = "Hello";
	//��ʾ�������ٸ��ַ�
	int num;
	printf("�����������ַ��ĸ���:");
	scanf("%d", &num);
	//���庯��ָ������ΪPtr
	typedef void(*Ptr)(int,int);
	//���庯��ָ�����͵ı���
	Ptr point;
	//����
	point(a,num);   
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