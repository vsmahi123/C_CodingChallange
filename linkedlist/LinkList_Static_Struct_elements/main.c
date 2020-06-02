#include<stdio.h>
#include<string.h>
#include"LinkListApi.h"
int main()
{
	char ch            = 0U;
	unsigned int index = 0U;
	linkList *head     = NULL;
	while(1)
		{
			__fpurge(stdin);
			printf("------------------ M E N U ------------------\n");
			printf("| enter:                                    | \n");
         printf("| [  1  ] to add entry at end               | \n");
			printf("| [  2  ] add entry at start                | \n");
			printf("| [  3  ] add node to middle                | \n");
			printf("|-------------------------------------------| \n");
			printf("| [  4  ] to display all                    | \n");
			printf("| [  5  ] to display by index               | \n");
			printf("|-------------------------------------------| \n");
			printf("| [  6  ] delete from end                   | \n");
			printf("| [  7  ] delete from start                 | \n");
			printf("| [  8  ] delete from middle                | \n");
			printf("| [ q/Q ] QUIT                              | \n");
			printf("---------------------------------------------\n");
			ch=getchar();
			switch(ch)
			{
				case '1': 
					puts("1 entered");
					head = addToEnd(head);
               //	printf("%d %s %d\n",head->roll,head->name,head->res);
               break;
				case '4': dispList(head);
               break;
				case '5':
					printf("enter index number:");
					scanf("%u",&index);
					displayindeX(head,index,IRVRead());
					break;
				case '2':
					head = addToStart(head);
					break;
				case '3':
					head = addNodeToMiddle(head);
					break;
				case '6':
					head = deleteFromEnd(head);
					break;
				case '7':
					head = deleteFromStart(head);
					break;
				case '8':
					head = deleteFromMiddle(head);
					break;
				default :
					ch =0;
               break;
			}
			if(ch == 0) break;
		}
	return 0;
}
