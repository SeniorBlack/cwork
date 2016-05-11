/*
	learn c array
	*/

#include <stdio.h>

int main() {
	char g_memeory_space[20] = "new rock!";
	printf("print char:\n");
	int i;
	for(i = 0;;i++) {
		printf("%c ", g_memeory_space[i]);
		if(g_memeory_space[i] == '\0' ) {
			printf("\n");
			break;
		}
	}
	printf("print string:\n");
	printf("%s\n", g_memeory_space);
	return 0;
}

/*
	output:
	
	print char:
    n e w   r o c k !  
    print string:
    new rock!

*/