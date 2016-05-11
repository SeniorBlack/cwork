/*
	learn c point3
	*/

#include <stdio.h>
#include <stdlib.h>

typedef struct student {
	char *name; //记录名字
	int score; //记录分数
}S_STUDENT_SCORE;  //定义一个结构体

int main() {
	//使用静态内存
	S_STUDENT_SCORE g_student_list[100];
	g_student_list[0].name = "Jimmy";
	g_student_list[0].score = 99;
	printf("name = %s\nscore = %d\n", g_student_list[0].name, g_student_list[0].score);

	//使用动态内存
	S_STUDENT_SCORE *p_student;
	p_student = (S_STUDENT_SCORE*)malloc(sizeof(S_STUDENT_SCORE));
	p_student->name = "Jimmy";
	p_student->score = 99;
	printf("name = %s\nscore = %d\n", p_student->name, p_student->score);
	free(p_student);
	return 0;
}

/*
	output:
	
	name = Jimmy
	score = 99
	name = Jimmy
	score = 99

*/