///模拟实现strcpy
//#include<stdio.h>
//#include<stdlib.h>
//char* myStrcpy(char* dest, const char* src){
//	if (src == NULL || dest == NULL){
//		return NULL;
//	}
//	char* dest1 = dest;
//	while (*src != '\0'){
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = '\0';
//	//printf("%s\n", dest1);
//	return dest1;
//}
//int main()
//{
//	char str1[1024] = "ABCD";
//	char str2[1024] = " ";
//	if (str1 != NULL){
//		printf("%s\n", myStrcpy(str1, "ffff"));
//	}
//	//printf("str1=%s\nstr2=%s\n", str1, str2);
//	system("pause");
//	return 0;
//}

///模拟实现strstr
//#include<stdio.h>
//#include<stdlib.h>
//
//const char* myStrstr(const char* dest, const char* str){
//	if (dest == NULL || str == NULL){
//		return NULL;
//	}
//	const char* location = dest;
//	while (*location!='\0'){
//		const char* dest1 = location;
//		const char* str1 = str;
//		while (*dest1!='\0'&&*str1 != '\0'&&*dest1==*str1){
//			dest1++;
//			str1++;
//		}
//		if (*dest1 == '\0'){
//			return NULL;
//		}
//		if (*str1 == '\0'){
//			return location;
//		}
//		if (*dest1 != *str1){
//			location++;
//		}
//	}
//	return NULL;
//}
//int main()
//{
//	char str1[] = "ADCHK";
//	char str2[] = "DCH";
//	printf("str=%s\nstr2=%s\n", str1, str2);
//	if (str1 != NULL&&str2 != NULL){
//		printf("%s\n", myStrstr(str1, str2));
//	}
//	system("pause");
//	return 0;
//}

///模拟实现strcat
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
char* myStrcat(char* dest, const char* str){
	if (dest == NULL&&str == NULL){
		return NULL;
	}
	char* dest1 = dest;
	dest=(dest + strlen(dest));
	while (*str!='\0'){
		*dest++ = *str++;
	}
	*dest = '\0';
	return dest1;
}
int main()
{
	char dest[1024] = "my ";
	char* str = "student.";
	printf("dest=%s\nstr=%s\n", dest, str);
	if (dest != NULL&&str != NULL){
		printf("%s\n", myStrcat(dest, str));
	}
	printf("%d\n",sizeof(long));
	system("pause");
	return 0;
}