///�ַ�����ת���
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//�ַ�����ת���
/*��Ŀ���ݣ�
дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����

���磺����s1 = AABCD��s2 = BCDAA������1

����s1 = abcd��s2 = ACBD������0.

AABCD����һ���ַ��õ�ABCDA

AABCD���������ַ��õ�BCDAA

AABCD����һ���ַ��õ�DAAB
*/
//����
int leftRotate(char str[], int length,char str1[]){
	char* a = str;
	char temp = 0;
	for (int i = 1; i <= length; i++){
		//���ַ�����һ���ַ���ʱ����temp.
		temp = *a;
		for (; a + 1 < a+strlen(a); a++){
			*a = *(a + 1);
		}
		//�����һ���ַ�('\0'ǰһ��Ԫ��)��ֵ.
		*a = temp;
		//�������ʼ��ָ�븳ֵ��a.
		a = str;
		//printf("%s��%s�ǿ����໥��ת��\n", str, str1);
		if (strcmp(str, str1) == 0){
			printf("�ǿ����໥��ת��\n", str, str1);
			return 1;
		}
	}
	printf("������ת��Ľ��\n");
	return 0;
}
int main()
{
	char str[] = "ABCD";
	char str1[] = "CDAB";
	printf("%s��%s\n", str, str1);
	int ret=leftRotate(str, strlen(str),  str1);
	printf("%d\n", ret);
	system("pause");
	return 0;
}

////������
/*#include<stdio.h>
#define PLAYER 5
/*������

��ҵ����
5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ����������

Aѡ��˵��B�ڶ����ҵ�����

Bѡ��˵���ҵڶ���E���ģ�

Cѡ��˵���ҵ�һ��D�ڶ���

Dѡ��˵��C����ҵ�����

Eѡ��˵���ҵ��ģ�A��һ��

����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
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
												printf("����Ϊ%d %d %d %d %d\n", a, b, c, d, e);
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