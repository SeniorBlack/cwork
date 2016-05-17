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

//在末尾添加时间戳分割的节点
void tail_add(data_node *head, char *p) {
	data_node *tmp = (data_node *)malloc(sizeof(data_node));
	strcpy(tmp->stamp, p);
	tmp->p_next = NULL;
	data_node *p_node =  NULL;
	for(p_node = head;p_node;p_node = p_node->p_next) {
		if(!p_node->p_next) {
			p_node->p_next = tmp;
			break;
		}
	}
	tmp = NULL;

}

//输出所有有节点到文件
void node_output(data_node *head) {
	FILE *p_outfile = fopen("output.log", "w");
	if(p_outfile == NULL) {
		printf("failed to open outfile");
		exit(1);
	}
	data_node *p_node =  NULL;
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
	data_node *head = NULL;
	//打开文件
	FILE *p_file = fopen("message.log", "r");
	if(p_file == NULL) {
		printf("failed to open file");
		exit(1);
	}
	//读取一个时间戳到str_buf
	while((ch=fgetc(p_file)) != EOF) {
		if(ch == "[") {
			if(str_buf[0] != '\0') {
				tail_add(head, str_buf);
			}
			memset(str_buf, '\0', 1024)
			continue;
		}
		int i = 0;
		str_buf[i++] = ch;
	}
	//输出所有节点
	node_outpt(head);       
	fclose(p_file);
	return 0;
}