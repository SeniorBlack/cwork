/*
	learn c point and array
	*/

#include <stdio.h>

int main() {
	int a[5] = {1, 2, 3, 4, 5};
	int *p1 = (int*)a;
	int *p2 = (int*)(&a + 1);
	printf("p1 = %p, p2 = %p\n", p1, p2);
	printf("v1 = %d, v2 = %d\n", *(a + 1), *(p2 - 1));
	return 0;
}

/*
	output:
	
	p1 = 0x7fffd43fe3c0, p2 = 0x7fffd43fe3d4
	v1 = 2, v2 = 5
	*/
