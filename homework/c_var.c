/*
	learn c var
*/

#include <stdio.h>

typedef struct node {
	int data;
	char ch[10];
}mynode;

int main() {
	int c_int = 44;
	char c_char = 'a';
	float c_f = 4.44;
	int arr[4] = {9, 5, 2, 7};
	mynode c_struct;
	c_struct.data = 77;
	char *p = "the cat";
	int m = 0;
	for(;*p!='\0';p++) {
		c_struct.ch[m] = *p;
		m++;
	}
	printf("c_int=%d\n", c_int);
	printf("c_char=%c\n", c_char);
	printf("c_f=%g\n", c_f);
	//打印数组
	printf("array :\n");
	int i;
	for(i = 0; i < 4; i++) {
		printf("%d", arr[i]);
	}
	printf("\n");
	//打印结构体
	int t;
	printf("struct:\n%d\n", c_struct.data);
	for(t = 0; t < m; t++) {
		printf("%c", c_struct.ch[t]);
	}
	printf("\n");
	return 0;
}


/*
	output:

	c_int=44
	c_char=a
	c_f=4.44
	array :
	9527
	struct:
	77
	the cat

*/