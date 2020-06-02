#ifndef LinkListApi_h
#define LinkListApi_h
#include<stdlib.h>
#define roll 0
#define res 1
struct data
{
	unsigned int intd[2];
	char name[30];
	struct data *next;

};
typedef struct data linkList;

linkList * createNode();

linkList* addToEnd(linkList *list);
linkList* addToStart(linkList *list);
void dispList(linkList *list);
void dispCurNode(linkList node);
void displayindeX(linkList *list,unsigned int index,unsigned int totNodes);
void IRVWrite(unsigned int cnt);
unsigned int IRVRead();




#endif 