//指针和数组
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	//int a[] = { 1, 2, 3, 4 };
	//printf("%d\n", sizeof(a));//数组所占的总空间
	//printf("%p\n", sizeof(a));//总空间数用16地址表示
	//printf("%0x\n", sizeof(a));//总空间数用16进制表示
	//printf("%d\n", sizeof(a + 0));//sizeof(*) 4
	//printf("%d\n", sizeof(a + 1));//sizeof(*) 4
	//printf("%d\n", sizeof(*a));//sizeof(a[0]) 4
	//printf("%d\n", sizeof(&a));// sizeof(*) 4
	//printf("%d\n", sizeof(&a + 1));//sizeof(*) 4
	////printf("%d\n", (&a));
	////printf("%d\n", (&a+1));
	//printf("%d\n", sizeof(&a[0]));//指针
	///*printf("%p\n", (&a[0]));
	//printf("%p\n", (&a[0]+1));*/
	//printf("%d\n", sizeof(&a[0] + 1));

	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	//printf("%d\n", sizeof(arr));//数组占空间大小6
	//printf("%d\n", sizeof(arr + 0));//指针4
	//printf("%d\n", sizeof(arr + 1));//指针4
	//printf("%d\n", arr);
	//printf("%d\n", arr+1);
	//printf("%d\n", &arr);
	//printf("%d\n", &arr + 1);
	//printf("%d\n", sizeof(&arr));//这个数组的指针4
	//printf("%d\n", sizeof(&arr + 1));//整个数组的指针4
	//printf("%d\n", sizeof(*arr));//1
	//printf("%d\n", sizeof(&arr[0]+1));//4
	//printf("%d\n", sizeof(&arr[0]));//4

	/*printf("%d\n", strlen(arr));
	printf("%d\n", strlen(arr + 0));
	printf("%d\n", strlen(*arr));
	printf("%d\n", strlen(arr[1]));
	printf("%d\n", strlen(&arr));
	printf("%d\n", strlen(&arr + 1));
	printf("%d\n", strlen(&arr[0] + 1));*/

	//char arr[] = "abcdef";
	///*printf("%d\n", sizeof(arr));
	//printf("%d\n", sizeof(arr + 0));
	//printf("%d\n", sizeof(*arr));
	//printf("%d\n", sizeof(arr[1]));
	//printf("%d\n", sizeof(&arr));
	//printf("%d\n", sizeof(&arr + 1));
	//printf("%d\n", sizeof(&arr[0] + 1));*/

	//printf("%d\n", strlen(arr));//6
	//printf("%d\n", strlen(arr + 0));//6
	////printf("%d\n", strlen(*arr));//传地址
	////printf("%d\n", strlen(arr[1]));//传地址
	//printf("%d\n", strlen(&arr));//6
	//printf("%d\n", strlen(&arr + 1));//超范围
	//printf("%d\n", strlen(&arr[0]+1));//5

	
	char *p = "abcdef";
	//printf("%d\n", sizeof(p));//4
	//printf("%d\n", sizeof(p + 1));//4
	//printf("%d\n", sizeof(*p));//1
	//printf("%d\n", sizeof(p[0]));//1
	//printf("%d\n", sizeof(&p));//4
	//printf("%d\n", sizeof(&p + 1));//超范围4
	//printf("%d\n", sizeof(&p[0] + 1));//4
	//printf("%d\n", strlen(p));//6
	//printf("%d\n", strlen(p + 1));//5
	//printf("%d\n", strlen(*p));//wu
	//printf("%d\n", strlen(p[0]));//wu
	printf("%d\n", strlen(&p));//6
	//printf("%d\n", strlen(&p + 1));//超范围
	//printf("%d\n", strlen(&p[0] + 1));//5
	//二维数组
	/*int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(a[0][0]));
	printf("%d\n", sizeof(a[0]));
	printf("%d\n", sizeof(a[0] + 1));
	printf("%d\n", sizeof(*(a[0] + 1)));
	printf("%d\n", sizeof(a + 1));
	printf("%d\n", sizeof(*(a + 1)));
	printf("%d\n", sizeof(&a[0] + 1));
	printf("%d\n", sizeof(*(&a[0] + 1)));
	printf("%d\n", sizeof(*a));
	printf("%d\n", sizeof(a[3]));*/ 
	
	system("pause");
	return 0;
}


///数组名,数组名取地址区别
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	//指针数组
//	int p1[10] = { 0 };
//	//数组首元素的地址
//	printf("p1=%p\n", p1);
//	printf("p1+Ox1=%p\n", p1+0x1);
//	printf("%d\n", ( p1 + 1 )- p1);
//	//整个数组的首地址
//	printf("&p1=%p\n", &p1);
//	printf("&p1+1=%p\n", &p1+1);
//	printf("%p\n", ( &p1 + 1 )- &p1);
//	system("pause");
//	return 0;
//}
///直接将字符串==,比较的是首地址
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	char str1[] = "HelloWorld!\n";
//	char str2[] = "HelloWorld!\n";
//	char* str3 = "hello";
//	char* str4 = "hello";
//	//比较两个字符串的首地址
//	if (str1 == str2){
//		printf("str1 and str2 are same\n");
//	}
//	else{
//		printf("str1 and str2 are not same\n");
//	}
//	if (str3 == str4){
//		printf("st3 and str4 are same\n");
//	}
//	else{
//		printf("str3 and str4 are not same\n");
//	}
//	system("pause");
//	return 0;
//}