#include<stdio.h>
#define PLAYER 5
/*
//猜名次
//*5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
//如果某几位的排名一样,返回1;
//否则返回0.
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
	//二维数组的每一行代表一个选手,每一行有5列,每一列代表每个选手的名次
	//0-4分别代表a-d
	//表示a说自己是第三名
	a[0][0] = 3;
	//表示a说b是第二名
	a[0][1] = 2;
	//表示b说b是第二名
	a[1][1] = 2;
	//表示b说e是第四名
	a[1][4] = 4;
	//表示c说自己是第一名
	a[2][2] = 1;
	//表示c说d是第二名
	a[2][3] = 2;
	//表示d说自己是第三名
	a[3][3] = 3;
	//表示d说c是第五名
	a[3][2] = 5;
	//表示d说自己是第四名
	a[4][4] = 4;
	//表示d说a是第一名
	a[4][0] = 1;
	//sort存放排序
	int sort[5] = { 0 };
	int is[5] = { 0 };
	//不同列,不同行
	for (int row = 0; row < PLAYER; row++){
		for (int col = 0; col < PLAYER;col++){

		}
	}
	/*for (int player = 0; player < 5; player++){
		for (int arr = 0; arr < 5; arr++){
			//判断该选手说是否对其他选手做出推测:有推测
			if (a[player][arr] != 0){
				//如果该位置还没有序列,对其进行赋值
				if (sort[arr] == 0&&iscommon(is,a[player][arr]==1)){
					sort[arr] = a[player][arr];
					a[player][arr] = 0;
					break;
				}
				//某位选手说的名次与该位置存放的序列一致
				//if (sort[arr] == a[player][arr])
				//否则扫描这个选手说的另一句话
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

///猜凶手
//*日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//	以下为4个嫌疑犯的供词:
//	A说：不是我。
//	B说：是C。
//	C说：是D。
//	D说：C在胡说
//	已知3个人说了真话，1个人说的是假话。
//	现在请根据这些信息，写一个程序来确定到底谁是凶手。*/
//int main()
//{
//	//k表示凶手
//	int k = 0;
//	//依次假设A~D为凶手
//	for (int k = 'A'; k <= 'D'; k++){
//		if ((k != 'A')+(k == 'C')+(k == 'D')+(k != 'D')==3){
//			printf("凶手是:%c\n", k);
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

// 如果是 大端 返回 1, 如果是 小端 返回 0
// 核心思路就是去除一个 int 的最低地址对应的字节, 看看是高位还是低位
int isBigEnd() {
int num = 0x11223344;
int* p = &num;
char* p2 = (char*)p;
if (*p2 == 0x11) {
return 1;
}
return 0;

// 不建议大家写成缩成一行的版本. 不利于理解.
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

// 谈到指针涉及到两方面的信息:
// 1. 房间号是几, p 变量内部存储的就是房间号
// 2. 房间大小是几. sizeof(Student) 就是房间大小.
//Student* p = &s;
//printf("%d\n", p->id);
//printf("%d\n", (*p).id);

////int a = 0x11223344;
//char name[] = "hello";

//printf("%d\n", isBigEnd());

//float a = 19.0;
//float b = a / 7.0;
//if (b * 7.0 == a) {
//	printf("相等!\n");
//} else {
//	printf("不相等\n");
//}

// 1e-4 => 1 * 10 ^ -4 => 0.0001
//   #define N 1e-4
//if (b * 7.0 - a < N && b * 7.0 - a > -N) {
//	printf("相等, 此处不是严格相等, 而是允许误差\n");
//} else {
//	printf("不相等\n");
//}



//float a = 1.0;
//float b = 2.0;
//float c = a + b;
//if (a + b == 3.0) {
//	printf("相等\n");
//} else {
//	printf("不相等\n");
//}

//char a = 'a';
//char* p = &a;

//char name[1024] = "zhangsan";
//char* p2 = name;

//char str1[] = "hehe";
//char str2[] = "hehe";
//char* str3 = "hehe";
//char* str4 = "hehe";

//// 此处数组本来是不能直接比较的.
//// 但是指针可以. 此处数组名又隐式转成指针了.
//if (str1 == str2) {
//	printf("相等\n");
//} else {
//	printf("不相等\n");
//}

//if (str3 == str4) {
//	printf("相等\n");
//} else {
//	printf("不相等\n");
//}

//int* arr[4] = { 0 };

//int arr2[4] = { 0 };
//int(*p)[4] = &arr2;

//printf("%p\n", arr2);
//// arr2 单独拎出来是 int* (首元素的指针)
//printf("%p\n", arr2 + 1);
//// &arr2 单独拎出来 是 int(*)[4] (指向数组的指针)
//printf("%p\n", &arr2 + 1);

// 长度为 3 的一维数组, 里面的每个元素又是长度为 5 的一维数组.
int arr[3][5] = { 0 };
print(arr);

system("pause");
return 0;
} */

///**在屏幕上打印杨辉三角。
//1
//
//1 1
//
//1 2 1
//
//1 3 3 1*/
////打印杨辉三角
#define LAYER 6
void print(int a[LAYER][LAYER]){
	printf("杨辉三角\n");
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
//杨辉三角
void trangle(){
	int a[LAYER][LAYER] = { 0 };
	a[0][0] = 1;
	for (int row = 1; row < LAYER; row++){
		for (int col = 0; col < LAYER; col++){
			//第一列全为1;
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
//主函数
int main()
{
		trangle();
		system("pause");
		return 0;
}