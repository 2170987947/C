//ָ�������
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	//int a[] = { 1, 2, 3, 4 };
	//printf("%d\n", sizeof(a));//������ռ���ܿռ�
	//printf("%p\n", sizeof(a));//�ܿռ�����16��ַ��ʾ
	//printf("%0x\n", sizeof(a));//�ܿռ�����16���Ʊ�ʾ
	//printf("%d\n", sizeof(a + 0));//sizeof(*) 4
	//printf("%d\n", sizeof(a + 1));//sizeof(*) 4
	//printf("%d\n", sizeof(*a));//sizeof(a[0]) 4
	//printf("%d\n", sizeof(&a));// sizeof(*) 4
	//printf("%d\n", sizeof(&a + 1));//sizeof(*) 4
	////printf("%d\n", (&a));
	////printf("%d\n", (&a+1));
	//printf("%d\n", sizeof(&a[0]));//ָ��
	///*printf("%p\n", (&a[0]));
	//printf("%p\n", (&a[0]+1));*/
	//printf("%d\n", sizeof(&a[0] + 1));

	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	//printf("%d\n", sizeof(arr));//����ռ�ռ��С6
	//printf("%d\n", sizeof(arr + 0));//ָ��4
	//printf("%d\n", sizeof(arr + 1));//ָ��4
	//printf("%d\n", arr);
	//printf("%d\n", arr+1);
	//printf("%d\n", &arr);
	//printf("%d\n", &arr + 1);
	//printf("%d\n", sizeof(&arr));//��������ָ��4
	//printf("%d\n", sizeof(&arr + 1));//���������ָ��4
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
	////printf("%d\n", strlen(*arr));//����ַ
	////printf("%d\n", strlen(arr[1]));//����ַ
	//printf("%d\n", strlen(&arr));//6
	//printf("%d\n", strlen(&arr + 1));//����Χ
	//printf("%d\n", strlen(&arr[0]+1));//5

	
	char *p = "abcdef";
	//printf("%d\n", sizeof(p));//4
	//printf("%d\n", sizeof(p + 1));//4
	//printf("%d\n", sizeof(*p));//1
	//printf("%d\n", sizeof(p[0]));//1
	//printf("%d\n", sizeof(&p));//4
	//printf("%d\n", sizeof(&p + 1));//����Χ4
	//printf("%d\n", sizeof(&p[0] + 1));//4
	//printf("%d\n", strlen(p));//6
	//printf("%d\n", strlen(p + 1));//5
	//printf("%d\n", strlen(*p));//wu
	//printf("%d\n", strlen(p[0]));//wu
	printf("%d\n", strlen(&p));//6
	//printf("%d\n", strlen(&p + 1));//����Χ
	//printf("%d\n", strlen(&p[0] + 1));//5
	//��ά����
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


///������,������ȡ��ַ����
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	//ָ������
//	int p1[10] = { 0 };
//	//������Ԫ�صĵ�ַ
//	printf("p1=%p\n", p1);
//	printf("p1+Ox1=%p\n", p1+0x1);
//	printf("%d\n", ( p1 + 1 )- p1);
//	//����������׵�ַ
//	printf("&p1=%p\n", &p1);
//	printf("&p1+1=%p\n", &p1+1);
//	printf("%p\n", ( &p1 + 1 )- &p1);
//	system("pause");
//	return 0;
//}
///ֱ�ӽ��ַ���==,�Ƚϵ����׵�ַ
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	char str1[] = "HelloWorld!\n";
//	char str2[] = "HelloWorld!\n";
//	char* str3 = "hello";
//	char* str4 = "hello";
//	//�Ƚ������ַ������׵�ַ
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