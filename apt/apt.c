/*
	app log 分析工具(APT)
	by 马爽
	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char stamp[1024];
	struct node *p_next;
} data_node;

data_node *head = NULL;
//在末尾添加时间戳分割的节点
void tail_add(char *p) {
	data_node *tmp = (data_node *)malloc(sizeof(data_node));
	strcpy(tmp->stamp, p);
	tmp->p_next = NULL;
	if(head == NULL) {
		head = tmp;
	} else { 
		data_node *p_node =  NULL;
		for(p_node = head;p_node;p_node = p_node->p_next) {
			if(!p_node->p_next) {
				p_node->p_next = tmp;
				break;
			}
		}
	}
	tmp = NULL;
}

//根据被叫号码找Call-ID
char *

//输出所有有节点到文件
void node_output() {
	FILE *p_outfile = fopen("output.log", "w");
	if(p_outfile == NULL) {
		printf("failed to open outfile");
		exit(1);
	}
	data_node *p_node =  NULL;
	fwrite(head->stamp, strlen(head->stamp), 1, p_outfile);
	for (p_node = head;p_node;p_node = p_node->p_next) {
        if (p_node->p_next) {
            fwrite(p_node->p_next->stamp, strlen(p_node->p_next->stamp), 1, p_outfile);
        }
    }
    fclose(p_outfile);
}



int main() {
	char ch;
	char str_buf[1024] = {'\0'};
	char buffer[128] = {'\0'};
	//打开文件
	FILE *p_file = fopen("message.log", "r");
	if(p_file == NULL) {
		printf("failed to open file");
		exit(1);
	}
	//读取一个时间戳到str_buf
	while(fgets(buffer, 128, p_file) != NULL) {
		strcat(str_buf, buffer);
		printf("buffer = %s, str_buf = %s\n", buffer, str_buf);
		if(strchr(str_buf, '[')) {
			tail_add(str_buf);
			memset(str_buf, '\0', 1024);
		}
		buffer[0] = '\0';
	}
	//输出所有节点到文件
	node_output(head);       
	fclose(p_file);
	return 0;
}
