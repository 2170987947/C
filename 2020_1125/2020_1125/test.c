#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
///ģ��ʵ��strncat
char* myStrncat(char* destination, const char* source, size_t num){
	if (destination == NULL){
		return NULL;
	}
	if (source == NULL){
		return destination;
	}
}
int main(){
	char dest[1024] = "I am ";
	const char source[] = "a student!";
	if (dest != NULL&&*source != '\0'){
		printf("strncat=%s\n",
			strncat(dest, source, strlen(source)));
	}
	//printf("%s\n", myStrncat(dest, source,  strlen(source)));
	system("pause");
	return 0;
}


///ģ��ʵ��atoi
////��C�ַ�������������
////�ڽ�����ʮ���������Ĺ�����,��������,�������Ųſ�ʼת��
////�������ո��ַ�,��ֱ�ӷ���,����������.
////���������ľͽ���ת��.
////����1A2,��ת������1,��Ϊ������A�ͽ�����ת����,����ľͲ�ִ����.
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int myAtoi(const char* str){
//	//���ű�־λ,Ĭ��������
//	int flag = 1;
//	//������ֵ������ret��
//	int ret = 0;
//	//������ַ����ǿյ�,����ʮ��������0
//	if (str == NULL){
//		return 0;
//	}
//	//�����ո��ַ��������������Ч�ַ�
//	while(*str == ' '){
//		str++;
//	}
//	//��������λ,����һ���ַ�
//	if (*str == '-'){
//		//������Ϊ��Ϊ-1
//		flag = -1;
//		str++;
//	}
//	while (*str >= '0' && *str <= '9'){
//		//���ַ�'0'��ȥ�Ϳ��Եõ�����������,��Ϊ�ַ�'0'��ASCII����
//		//*str-'0'�պþ���ASCII����Ӧ��ֵ���
//		//����'9'-'0'=9
//		ret=ret*10+*str-'0';
//		str++;
//	}
//	return flag*ret;
//
//}
//int main()
//{
//	const char str1[] = "    1e3lo";
//	const char str2[] = "123344";
//	const char str3[] = "A";
//	printf("str1=%s\n", str1);
//	printf("atoi(str1)=%d\n", atoi(str1));
//	printf("myAtoi(str1)=%d\n\n", myAtoi(str1));
//	printf("str2=%s\n", str2);
//	printf("atoi(str2)=%d\n", atoi(str2));
//	printf("myAtoi(str2)=%d\n\n", myAtoi(str2));
//	printf("str3=%s\n", str3);
//	printf("atoi(str3)=%d\n", atoi(str3));
//	printf("myAtoi(str3)=%d\n", myAtoi(str3));
//
//	system("pause");
//	return 0;
//}