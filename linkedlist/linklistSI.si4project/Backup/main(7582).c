#include<stdio.h>
#include<string.h>
#include"LinkListApi.h"
int main()
{
	char ch=0;
	linkList *head = NULL;
	while(1)
		{
			__fpurge(stdin);
			puts("enter 1 to add entry 2 to display all");
			ch=getchar();
			switch(ch)
			{
				case '1': 
					puts("1 entered");
					head = addToEnd(head);
				break;
				case '2': dispList(head);
				break;
				default :
					ch =3;
				break;
			}
			if(ch == 3) break;
		}
	return 0;
}
