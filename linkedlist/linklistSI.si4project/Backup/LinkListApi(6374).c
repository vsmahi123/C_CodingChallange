#include"LinkListApi.h"
#include<stdio.h>
#include<string.h>
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
	printf("\n-----------in add to end-----------\n");
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
	printf("\n*************************\n");

	printf("-----------number of entries[ %u ]------------\n",IRVRead());
	if(list != NULL)
	{
		while(dum!= NULL)
		
		{
			printf("roll : %u	name:  ",dum->intd[roll]);
			printf("%s",dum->name);
			if(dum->intd[res] == 1) printf("result : pass\n");
			else if(2 == dum->intd[res]) printf("result : failed\n");
			//printf("%d\n*************************\n",dum->res);
			dum=dum->next;
			
		}
	}
	else
	{
		puts("empty list");
	}
	printf("\n**************************\n");
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

	printf("\n-----------------in add to start -----------\n");

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
	printf("\n----------------- Creating a node -----------\n");

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


linkList* addNodeToMiddle(linkList *list)
{
	printf("\n----------------- in add to middle -----------\n");

	linkList *node = NULL,*slowPtr = list ,*fastPtr = list;
	node=createNode();
	unsigned int cnt= IRVRead();
	cnt++;

	if(list == NULL)
	{
		list =node;
	}
	else
	{
		while(fastPtr->next && fastPtr->next->next)
		{	

			fastPtr = fastPtr->next->next;
			slowPtr = slowPtr->next;
		}

		dispCurNode(*slowPtr);

		node->next = slowPtr->next;
		slowPtr->next = node;
	}
	IRVWrite(cnt);
	
	return list;

	
	
}





linkList* deleteFromEnd(linkList * list)
{
	linkList *dum = list;
	unsigned int cnt = IRVRead();
	printf("\n-----------in delete from end-----------\n");
	if(dum)
	{
		cnt--;
		while(dum->next && dum->next->next)
			{
				dum=dum->next;
			}
		if(dum->next == NULL)
		{
			list = deleteFromStart(list);
		}
		else
		{
			
			dum->next->intd[res] = 0;
			dum->next->intd[roll] = 0;
			strcpy(dum->next->name,"\0");
			
			free(dum->next);
			dum->next = NULL;
		}
	}

	IRVWrite(cnt);
	return list;
	
}

linkList* deleteFromStart(linkList * list)
{
	linkList* dum =NULL;
	unsigned int cnt = IRVRead();
	printf("\n-----------in delete from start-----------\n");

	if(list)
	{
		cnt--;
		 if(list->next)
		 {
			dum=list->next;
			list->intd[res] = 0;
			list->intd[roll] = 0;
			strcpy(list->name,"\0");
			list->next = NULL;
		 		free(list);
				 list = dum;
				 
				/*dispList(list);
				printf("\n-----displaying dum----\n");
				dispList(dum);*/
				
	
		 }
		 else
		 {
		 free(list);
		 list = NULL;
		 	
		 	
		 }

	}
	else
	{
	
	}
	IRVWrite(cnt);
	
	return list;
}




/*for delete function solve the bug 
1. if 2 node

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


						FUNCTIONS NOT RUNNING WELL WORK ON IT : comment date : 07-01-2020 01:01 AM

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/


linkList* deleteFromMiddle(linkList * list)
{
	linkList* fptr=list,*sptr=list,*dum=NULL,*lastptr=NULL;
	unsigned int cnt = IRVRead();
	lastptr = sptr;
	printf("\n-----------in delete from middle-----------\n");
	if(list)
		{
		cnt--;
		
			
			
			while(fptr->next && fptr->next->next)
			{
				fptr=fptr->next->next;
				lastptr = sptr;
				sptr=sptr->next;
			} 
			if(sptr->next && (sptr->next->next  || (sptr->next->next == NULL)))
			{
				if(lastptr == NULL)
				{
					list = deleteFromStart(list);
				}
				else
				{
					lastptr->next=sptr->next;
					free(sptr);
					sptr=NULL;
				}
			}
			/*else if(sptr->next && (sptr->next->next == NULL))
			{
				
			}*/
			/*else
			{
				list = deleteFromStart(list);

			}*/
			
			
		}
	IRVWrite(cnt);
	return list;
}

