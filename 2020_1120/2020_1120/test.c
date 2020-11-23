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
	printf("%p\n", dest);
	printf("%p\n", src);
	printf("%p\n", src1+num);
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
	int dest[4] = { 0 };
	int  src[4] = { 1,2,3,4 };
	if (dest != NULL&&src != NULL){
		//myMemcpy(dest, src, sizeof(src));
		myMemmove(dest, src, sizeof(src));
	}
	for (int i = 0; i < 4;i++){
		printf("%d\t", dest[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

///模拟实现memcpy
