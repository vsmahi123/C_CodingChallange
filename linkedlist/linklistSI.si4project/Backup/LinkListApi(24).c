#include"LinkListApi.h"
#include<stdio.h>
static unsigned int nodeCnt = 0;

void IRVWrite(unsigned int cnt)
{
	
	static unsigned int lock=0;
	if(lock == 0)
	{
		lock=1;
		nodeCnt = cnt;
		lock =0;
	}
	return;
	
}

unsigned int IRVRead()
{
	return nodeCnt;

}

linkList* addToEnd(linkList *list)
{
	linkList *node=NULL ,*dum = list;
	unsigned int cnt=IRVRead();
	
	//printf("size of struct ptr :%d,size of struct : %d\n*************\n",sizeof(linkList *),sizeof(linkList));
		node = createNode();
		
		if(list==NULL)
	{
		printf("list is null\n adding new node\n");
	list = node;
	//dispList(list);
	}
	else
	{
		dum = list;
		while(dum->next != NULL)
			{
				dum = dum->next;
			}
		if(dum->next == NULL)
			{
				//printf("!!!!!!!!!!!!!!traverse complete null found!!!!!!!!!!!!!!");
				dum->next = node;
				//printf("%d %s %d\n",dum->next->intd[res],dum->next->name,dum->next->intd[res]);
			}
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

	cnt++;
	IRVWrite(cnt);
	return (linkList*)dum;
}


void dispList(linkList* list)
{
	linkList *dum = list;

	printf("entries --  %u",IRVRead());
	if(list != NULL)
	{
		while(dum!= NULL)
		{
			printf("\n*************************\n");
			printf("roll : %u\nname:  ",dum->intd[roll]);
			puts(dum->name);
			if(dum->intd[res] == 1) printf("result : pass\n**************************\n");
			else if(2 == dum->intd[res]) printf("result : failed\n**************************\n");
			//printf("%d\n*************************\n",dum->res);
			dum=dum->next;
			
		}
	}
	else
	{
		puts("empty list");
	}
}


void displayindeX(linkList * list, unsigned int index,unsigned int totNodes)
{
	linkList *dum = list;
	
	if(index>totNodes-1) 
		{
			printf("there are only %d nodes so node with index %d dosent exist!!",totNodes,index);
		return;
		}
	
	while(index !=0)
	{
		dum= dum->next;
	
	index--;
	}
	dispCurNode(*dum);
		
}


void dispCurNode(linkList node)
{
	printf("\n************************************\n");
	printf("%u	",node.intd[roll]);
	printf("%s	",node.name);
	printf("%u",node.intd[res]);
	printf("\n************************************\n");
}

linkList* addToStart(linkList * list)
{

	linkList *node=NULL;
	unsigned int cnt =IRVRead();
	node =createNode();
	node->next=list;
	cnt++;
	IRVWrite(cnt);
	return node;


}


linkList* createNode()
{
linkList *node =NULL;
	node = malloc(1*sizeof(linkList));
		/*as we are using static entry we need to consider size of total structure not the structure pointer as the pointer already 
		have space but where it is pointing is exact data not the pointer so conside the size of the structure*/
				if(node == NULL)
					printf("mem alloc error\n*******\n");
				
				puts("enter roll:");
				scanf("%d",&(node->intd[roll]));
				puts("enter name:");
				__fpurge(stdin);
				scanf("%[^\n]s",node->name);
				puts("enter result:");
				scanf("%d",&(node->intd[res]));
		
				node->next = NULL;
return node;
}

