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

char * mystrcpy(char *dest, const char *src) {
	while(1) {
		*dest = *src;
		if(*src == '\0') {
			break;
		}
		dest++;
		src++;
	}
	return dest;
}
int main() {
	//mystrlen():
	printf("mystrlen(new rock cloud) = %d\n", mystrlen("new rock cloud"));
	//mystrcpy():
	char dest[20] = {'n', 'e', 'w', '\0'};
	char *src = "hello, newrock!";
	printf("dest[20] = %s, src = %s, mystrcpy(dest, src) = %s\n", dest, src, mystrcpy(dest, src));
	return 0;
}