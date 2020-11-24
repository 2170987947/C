///模拟实现memmove
#include<stdio.h>
#include<stdlib.h>

void* myMemcpy(void* dest, const void* src, size_t num){
	if (dest == NULL || src == NULL){
		return NULL;
	}
	char* dest1 = (char*)dest;
	char* src1 = (char*)src;
		for (size_t i = 0; i < num; i++){
			dest1[i] = src1[i];
		}
	return dest;
}

void* myMemmove(void* dest, const void*src, size_t num){
	if (dest == NULL || src == NULL){
		return NULL;
	}
	char* dest1 = (char*)dest;
	const char* src1 = (char*)src;
	//如果dest包含在src中（有重叠）反着拷贝
	if (src1 <= dest1&&dest1 <= (src1 + num)){
		//反着拷贝
		for (size_t i = num-1; i > 0; i--){
			dest1[i] = src1[i];
		}
		return dest;
	}
	else{
		for (size_t i = 0; i < num; i++){
			dest1[i] = src1[i];
		}
		return dest;
	}
}

int main()
{
	int dest1[4] = { 0 };
	int  src1[4] = { 1,2,3,4 };
	int dest2[4] = { 0 };
	int  src2[4] = { 2, 9, 1, 0 };
	if (dest1 != NULL&&src1 != NULL){
		myMemcpy(dest1, src1, sizeof(src1));
	}
	printf("myMemcpy函数 dest1: ");
	for (int i = 0; i < 4;i++){
		printf("%d\t", dest1[i]);
	}
	printf("\n");
	if (dest1 != NULL&&src1 != NULL){
		myMemmove(dest2, src2, sizeof(src2));
	}
	printf("myMemmove函数 dest2: ");
	for (int i = 0; i < 4; i++){
		printf("%d\t", dest2[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

///模拟实现memcpy
