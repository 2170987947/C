#include<stdio.h>
#define PLAYER 5
/*
//������
//*5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ����������
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
//���ĳ��λ������һ��,����1;
//���򷵻�0.
//int iscommon(int is[PLAYER],int sort){
//	for (int i = 0; i < PLAYER;i++){
//		if (sort == is[i]){
//			return 1;
//		}
//	}
//	return 0;
//}


int main()
{
	int a[PLAYER][PLAYER] = { 0 };
	//��ά�����ÿһ�д���һ��ѡ��,ÿһ����5��,ÿһ�д���ÿ��ѡ�ֵ�����
	//0-4�ֱ����a-d
	//��ʾa˵�Լ��ǵ�����
	a[0][0] = 3;
	//��ʾa˵b�ǵڶ���
	a[0][1] = 2;
	//��ʾb˵b�ǵڶ���
	a[1][1] = 2;
	//��ʾb˵e�ǵ�����
	a[1][4] = 4;
	//��ʾc˵�Լ��ǵ�һ��
	a[2][2] = 1;
	//��ʾc˵d�ǵڶ���
	a[2][3] = 2;
	//��ʾd˵�Լ��ǵ�����
	a[3][3] = 3;
	//��ʾd˵c�ǵ�����
	a[3][2] = 5;
	//��ʾd˵�Լ��ǵ�����
	a[4][4] = 4;
	//��ʾd˵a�ǵ�һ��
	a[4][0] = 1;
	//sort�������
	int sort[5] = { 0 };
	int is[5] = { 0 };
	//��ͬ��,��ͬ��
	for (int row = 0; row < PLAYER; row++){
		for (int col = 0; col < PLAYER;col++){

		}
	}
	/*for (int player = 0; player < 5; player++){
		for (int arr = 0; arr < 5; arr++){
			//�жϸ�ѡ��˵�Ƿ������ѡ�������Ʋ�:���Ʋ�
			if (a[player][arr] != 0){
				//�����λ�û�û������,������и�ֵ
				if (sort[arr] == 0&&iscommon(is,a[player][arr]==1)){
					sort[arr] = a[player][arr];
					a[player][arr] = 0;
					break;
				}
				//ĳλѡ��˵���������λ�ô�ŵ�����һ��
				//if (sort[arr] == a[player][arr])
				//����ɨ�����ѡ��˵����һ�仰
				else continue;
			}
		}
	}
	for (int size = 0; size < PLAYER; size++){
		printf("%d\t", sort[size]);
	}
	printf("\n");
	system("pause");
	return 0;
}
*/

///������
//*�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
//	����Ϊ4�����ɷ��Ĺ���:
//	A˵�������ҡ�
//	B˵����C��
//	C˵����D��
//	D˵��C�ں�˵
//	��֪3����˵���滰��1����˵���Ǽٻ���
//	�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�*/
//int main()
//{
//	//k��ʾ����
//	int k = 0;
//	//���μ���A~DΪ����
//	for (int k = 'A'; k <= 'D'; k++){
//		if ((k != 'A')+(k == 'C')+(k == 'D')+(k != 'D')==3){
//			printf("������:%c\n", k);
//		}
//	}
//	system("pause");
//	return 0;
//}





/*#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
int id;
char name[1024];
} Student;

// ����� ��� ���� 1, ����� С�� ���� 0
// ����˼·����ȥ��һ�� int ����͵�ַ��Ӧ���ֽ�, �����Ǹ�λ���ǵ�λ
int isBigEnd() {
int num = 0x11223344;
int* p = &num;
char* p2 = (char*)p;
if (*p2 == 0x11) {
return 1;
}
return 0;

// ��������д������һ�еİ汾. ���������.
// return *((char*)(&num)) == 0x11;
}

//void print(int arr[3][5]) {
//
//}

//void print(int(*p)[5]) { //
//}

void print(int** p) {

}

int main() {

//Student s = { 10, "zhangsan" };
//printf("%d\n", s.id);

// ̸��ָ���漰�����������Ϣ:
// 1. ������Ǽ�, p �����ڲ��洢�ľ��Ƿ����
// 2. �����С�Ǽ�. sizeof(Student) ���Ƿ����С.
//Student* p = &s;
//printf("%d\n", p->id);
//printf("%d\n", (*p).id);

////int a = 0x11223344;
//char name[] = "hello";

//printf("%d\n", isBigEnd());

//float a = 19.0;
//float b = a / 7.0;
//if (b * 7.0 == a) {
//	printf("���!\n");
//} else {
//	printf("�����\n");
//}

// 1e-4 => 1 * 10 ^ -4 => 0.0001
//   #define N 1e-4
//if (b * 7.0 - a < N && b * 7.0 - a > -N) {
//	printf("���, �˴������ϸ����, �����������\n");
//} else {
//	printf("�����\n");
//}



//float a = 1.0;
//float b = 2.0;
//float c = a + b;
//if (a + b == 3.0) {
//	printf("���\n");
//} else {
//	printf("�����\n");
//}

//char a = 'a';
//char* p = &a;

//char name[1024] = "zhangsan";
//char* p2 = name;

//char str1[] = "hehe";
//char str2[] = "hehe";
//char* str3 = "hehe";
//char* str4 = "hehe";

//// �˴����鱾���ǲ���ֱ�ӱȽϵ�.
//// ����ָ�����. �˴�����������ʽת��ָ����.
//if (str1 == str2) {
//	printf("���\n");
//} else {
//	printf("�����\n");
//}

//if (str3 == str4) {
//	printf("���\n");
//} else {
//	printf("�����\n");
//}

//int* arr[4] = { 0 };

//int arr2[4] = { 0 };
//int(*p)[4] = &arr2;

//printf("%p\n", arr2);
//// arr2 ����������� int* (��Ԫ�ص�ָ��)
//printf("%p\n", arr2 + 1);
//// &arr2 ��������� �� int(*)[4] (ָ�������ָ��)
//printf("%p\n", &arr2 + 1);

// ����Ϊ 3 ��һά����, �����ÿ��Ԫ�����ǳ���Ϊ 5 ��һά����.
int arr[3][5] = { 0 };
print(arr);

system("pause");
return 0;
} */

///**����Ļ�ϴ�ӡ������ǡ�
//1
//
//1 1
//
//1 2 1
//
//1 3 3 1*/
////��ӡ�������
#define LAYER 6
void print(int a[LAYER][LAYER]){
	printf("�������\n");
	for (int row = 0; row < LAYER; row++){
		for (int col = 0; col < LAYER; col++){
			if (a[row][col] == 0){
				break;
			}
		printf("%d\t", a[row][col]);
		}
		printf("\n");
	}
}
//�������
void trangle(){
	int a[LAYER][LAYER] = { 0 };
	a[0][0] = 1;
	for (int row = 1; row < LAYER; row++){
		for (int col = 0; col < LAYER; col++){
			//��һ��ȫΪ1;
			if (col == 0){
				a[row][col] = 1;
			}
			else {
				a[row][col] = a[row - 1][col - 1] + a[row - 1][col];
			}
		}
	}
	print(a);
}
//������
int main()
{
		trangle();
		system("pause");
		return 0;
}