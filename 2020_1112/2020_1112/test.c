///�жϴ�С��
#include<stdio.h>
#include<stdlib.h>
//����˼��:ȡ��int����͵�ַ��Ӧ��һ���ֽ�,�����ŵ��Ǹ�λ���ǵ�λ.
//����Ǵ��,����1
//�����С��,����0;
int isBigEnd(int num){
	int* p = &num;
	char* p2 = (char*)p;
	//�����ŵ���11(��λ)
	if (*p2==0x11){
		return 1;
	}
	return 0;
}
int main()
{
	int num = 0x11223344;
	printf("����1��ʾ���\n����0��ʾС��\n");
	printf("%d\n", isBigEnd(num));
	system("pause");
	return 0;
}