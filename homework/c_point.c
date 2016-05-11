/*
	learn c point

	1.什么是指针？
	指针是一个存储另一个变量地址的整形变量。
	2.什么是数组？
	数组是一串连续的内存，用于存储相同类型的数据。
	3.指针和数组的关系
	指针的的值可以改变，数组名是数组的收地址，值不能改变。
	*/

#include <stdio.h>

int main() {
	printf("define point p:\n");
	int  A  = 10;    // 内存变量A 初始化为10
	int  *p = &A;    // p 是指针， 指向A的空间
	printf("A = %d\n", A);
	printf("*p = %d\n", *p);
	printf("p = %p\n", p);
	printf("clear p:\n");
	*p = 0;          // 这条命令把A所在地的内存清除了
	p = NULL;          // 这是把指针清空了， 这个指针就不能随便再用
	printf("A = %d\n", A);
	//printf("*p = %d\n", *p);//段错误
	//printf("p = %p\n", p); 
	return 0;
}

/*
	output:
	
	define point p:
	A = 10
	*p = 10
	p = 0x7ffffa59aac4
	clear p:
	A = 0

*/