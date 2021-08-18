#include<stdio.h>
#include<stdlib.h>
#include"binary_tree.h"
#define CHESS_SIZE 9*9
struct empty_pos{
	int pri;
	int pos;
};
static struct empty_pos* ptr;
static int chess[CHESS_SIZE];
void get_pri(int pos)
{

void initializeAll(const char *s)
{
	if(strlen(s)!=CHESS_SIZE){
		printf("Please enter the right number of chess");
		exit(EXIT_FAILURE);
	}
	int index = 0;
	int pos[CHESS_SIZE];
	for(int i=0;i<CHESS_SIZE;++i){
		chess[i] = atoi(*(s+i));
		if(*(s+i)=='0')pos[index++]=i;
	}
	ptr = malloc(index * sizeof(struct empty_pos));
	for(int i=0;i<index;++i){
		(ptr+i)->pos = pos[i];
	}
}

int main()
{
	return 0;
}


