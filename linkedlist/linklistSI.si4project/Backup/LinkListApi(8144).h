#ifndef LinkListApi_h
#define LinkListApi_h
#include<stdlib.h>
typedef struct data
{
	char name[30];
	unsigned int roll;
	unsigned int res ;
	struct data *next;

}linkList;

linkList* addToEnd(linkList *list);
void dispList(linkList *list);
void displayX(linkList *list,unsigned int index);


#endif 