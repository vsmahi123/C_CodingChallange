#include<stdio.h>
#include<string.h>
#include"LinkListApi.h"
int main()
{
	char ch=0;
	unsigned int index=0;
	linkList *head = NULL;
	while(1)
		{
			__fpurge(stdin);
			printf("enter 1 to add entry at end \n2 to display all\n3 to display by index\n");
			printf("4 add entry at start\n5 add node to middle \n");
			printf("6 delete from end\n");
			printf("7 delete from start\n");
			printf("8 delete from middle\n");
			ch=getchar();
			switch(ch)
			{
				case '1': 
					puts("1 entered");
					head = addToEnd(head);
				//	printf("%d %s %d\n",head->roll,head->name,head->res);
				break;
				case '2': dispList(head);
				break;
				case '3':
					printf("enter index number:");
					scanf("%u",&index);
					displayindeX(head,index,IRVRead());
					break;
				case '4':
					head = addToStart(head);
					break;
				case '5':
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
