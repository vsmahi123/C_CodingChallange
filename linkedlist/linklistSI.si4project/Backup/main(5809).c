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
			printf("4 add entry at start\n");
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
					
				default :
					ch =0;
				break;
			}
			if(ch == 0) break;
		}
	return 0;
}
