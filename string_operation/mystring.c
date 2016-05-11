/*
	用C代码实现字符串操作， strlen（）， strcpy（）， strchr（）， strcat（）
*/

#include <stdio.h>
	
size_t mystrlen(const char *s) {
	size_t len = 0;
	for(; *s != '\0'; s++) {
		len++;
	}
	return len;
}

int main() {
	printf("mystrlen(new rock cloud) = %d\n", mystrlen("new rock cloud"));
	return 0;
}