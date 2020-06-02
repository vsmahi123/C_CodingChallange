#include"LinkListApi.h"
#include<stdio.h>
static unsigned int cnt = 0;
linkList* addToEnd(linkList *list)
{
    cnt++;
	linkList *node=NULL ,*dum = list;
	
	
	printf("size of struct ptr :%d,size of struct : %d\n*************\n",sizeof(linkList *),sizeof(linkList));
	node = malloc(1*sizeof(linkList*));
			if(node == NULL)
				printf("mem alloc error\n*******\n");
			
			puts("enter roll:");
			scanf("%d",&(node->roll));
			puts("enter name:");
			__fpurge(stdin);
			scanf("%[^\n]s",node->name);
			puts("enter result:");
			scanf("%d",&(node->res));
	
			node->next = NULL;
	if(list==NULL)
	{
		printf("list is null\n");
	list = node;
	dispList(list);
	}
	else
	{
		dum = list;
		while(dum->next != NULL)
			{
				dum = dum->next;
			}
		dum->next = node;
	}

	dum=list;
	//printf("%d %s %d\n",node->roll,node->name,node->res);
		/*while(dum->next != NULL);
		{
			printf("%d",dum->roll);
			puts(dum->name);
			printf("%d\n*************************\n",dum->res);
			dum=dum->next;
			
		}*/

	
	return (linkList*)dum;
}


void dispList(linkList* list)
{
	linkList *dum = list;

	printf("entries --  %d",cnt);
	if(list != NULL)
	{
		while(dum!= NULL)
		{
			printf("\n*************************\n");
			printf("roll : %d\nname:  ",dum->roll);
			puts(dum->name);
			if(dum->res == 1) printf("result : pass\n**************************\n");
			else printf("result : failed\n**************************\n");
			//printf("%d\n*************************\n",dum->res);
			dum=dum->next;
			
		}
	}
	else
	{
		puts("empty list");
	}
}


