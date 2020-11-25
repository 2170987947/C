#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
///模拟实现strncat
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


///模拟实现atoi
////将C字符串解析成整数
////在解析成十进制整数的过程中,遇到数字,正负符号才开始转换
////和遇到空格字符,不直接返回,而是往后找.
////遇到其他的就结束转换.
////比如1A2,就转换成了1,因为其遇到A就结束了转换了,后面的就不执行了.
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int myAtoi(const char* str){
//	//符号标志位,默认是正数
//	int flag = 1;
//	//将返回值保存在ret中
//	int ret = 0;
//	//如果该字符串是空的,返回十进制整数0
//	if (str == NULL){
//		return 0;
//	}
//	//遇到空格字符就往后继续找有效字符
//	while(*str == ' '){
//		str++;
//	}
//	//遇到符号位,找下一个字符
//	if (*str == '-'){
//		//将符号为置为-1
//		flag = -1;
//		str++;
//	}
//	while (*str >= '0' && *str <= '9'){
//		//将字符'0'减去就可以得到真正的整数,因为字符'0'以ASCII码存放
//		//*str-'0'刚好就是ASCII码表对应的值相减
//		//比如'9'-'0'=9
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