/*
	name:	apt.c
	function:	app log 分析工具(APT)
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

//根据被叫号码找call_id
void find_call_id(char *to_number, char *call_id) {
	data_node *p_node =  NULL;
	char *num_match = NULL;
	char *call_id_match = NULL;
	for(p_node = head;p_node;p_node = p_node->p_next) {
		num_match = strstr(p_node->stamp, to_number);
		if(num_match) {
			call_id_match = strstr(p_node->stamp, "Call-ID");
			for(call_id_match = call_id_match + 9;*call_id_match != '\n';call_id_match++) {
				*call_id++ = *call_id_match; 
			}
			break;
		}

	}
}

//输出链表节点到文件,用call_id过滤
void node_output(char *call_id) {
	FILE *p_outfile = fopen("output.log", "w");
	if(p_outfile == NULL) {
		printf("failed to open outfile");
		exit(1);
	}
	data_node *p_node =  NULL;
	//fwrite(head->stamp, strlen(head->stamp), 1, p_outfile);
	for (p_node = head;p_node;p_node = p_node->p_next) {
		//printf("%s\n", p_node->stamp);
		if(strstr(p_node->stamp, call_id)) {
            fwrite(p_node->stamp, strlen(p_node->stamp), 1, p_outfile);
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
	int m = 0;
	//读取一个时间戳到str_buf,插入单向链表尾部
	while(fgets(buffer, 128, p_file) != NULL) {
		//strcat(str_buf2, buffer);
		//printf("buffer = %s, str_buf = %s\n", buffer, str_buf);
		if(strchr(buffer, '[')) {
			m++;
			if(m = 2) {
				tail_add(str_buf);
				memset(str_buf, '\0', 1024);
				m = 0;
			}
		}
		strcat(str_buf, buffer);
		buffer[0] = '\0';
	}
	//查找call-id
	char *to_number = "015861078585";
	char call_id[30] = {'\0'};
	find_call_id(to_number, call_id);
	printf("call_id= %s\n", call_id);
	//输出所有节点到文件
	node_output(call_id);       
	fclose(p_file);
	return 0;
}
