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
	char *dest_tmp = dest;
	while(1) {
		*dest = *src;
		if(*src == '\0') {
			break;
		}
		dest++;
		src++;
	}
	return dest_tmp;
}

char *mystrchr(const char *s, char c) {
	char *s_tmp = (char*)s;
	while(1) {
		if(*s == c){
			return s_tmp;
		} else if(*s == '\0') {
			return NULL;
		}
		s++;
	}
}

char *mystrcat(char *dest, const char *src) {
	char *dest_tmp = dest;
	while(1) {
		if(*dest == '\0') {
			while(1) {
				*dest = *src;
				if(*src == '\0') {
					return dest_tmp;
				}
				dest++;
				src++;
			}
		}
		dest++;
	}
}

int main() {
	//mystrlen
	printf("mystrlen():\n");
	printf("mystrlen(new rock cloud) = %d\n", mystrlen("new rock cloud"));
	//mystrcpy
	printf("mystrcpy():\n");
	char dest[20] = {'n', 'e', 'w', '\0'};
	char *src = "hello, newrock!";
	printf("dest[20] = %s\n", dest);
	printf("src = %s, mystrcpy(dest, src) = %s\n", dest, src, mystrcpy(dest, src));
	//mystrchr
	printf("mystrchr():\n");
	printf("mystrchr(\"newrock\", 'o') = %p\n", mystrchr("newrock", 'o'));
	//mystrcat
	printf("mystrcat():\n");
	char dest_cat[20] = "new";
	char *src_cat = "rock";
	printf("mystrcat(dest_cat, src_cat) = %s\n", mystrcat(dest_cat, src_cat));
	return 0;
}


/*
	output:

	mystrlen():
	mystrlen(new rock cloud) = 14
	mystrcpy():
	dest[20] = new
	src = hello, newrock!, mystrcpy(dest, src) = hello, newrock!
	mystrchr():
	mystrchr("newrock", 'o') = 0x4008e8
	mystrcat():
	mystrcat(dest_cat, src_cat) = newrock

*/
