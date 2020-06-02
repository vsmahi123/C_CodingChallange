#include"LinkListApi.h"
#include<stdio.h>
#include<string.h>
static unsigned int nodeCnt = 0;

void IRVWrite(unsigned int cnt)
{
   
   static unsigned int lock = LOCK;
   if(LOCK == lock)
   {
      lock = UNLOCK;
      nodeCnt = cnt;
      lock = LOCK;
   }
   return;
   
}

unsigned int IRVRead()
{
   return nodeCnt;
}

linkList* addToEnd(linkList *list)
{
   linkList *node = NULL ;
   linkList *dum  = list;
   
   unsigned int cnt=IRVRead();
   
   printf("\n-----------in add to end-----------\n");
   node = createNode();
      
   if(NULL == list)
   {
      list = node;
   }
   else
   {
      dum = list;
      while(NULL != dum->next )
      {
         dum = dum->next;
      }
      if(NULL == dum->next)
      {
         dum->next = node;
      }
   }

   dum=list;

   cnt++;
   IRVWrite(cnt);
   return (linkList*)dum;
}


void dispList(linkList* list)
{
   linkList *dum = list;
   printf("\n**********************************************\n");

   printf("----------- number of entries[ %u ] -----------\n",IRVRead());
   if(NULL  != list)
   {
      while(NULL != dum)
      {
         printf("roll : %u   name:  ",dum->intd[roll]);
         printf("%s",dum->name);
         if(dum->intd[res] == 1) printf("   result : pass\n");
         else if(2 == dum->intd[res]) printf("   result : failed\n");
         else printf("   result : failed\n");
         dum=dum->next;
         
      }
   }
   else
   {
      puts("empty list");
   }
   printf("\n**********************************************\n");
}


void displayindeX(linkList * list, unsigned int index,unsigned int totNodes)
{
   linkList *dum = list;
   
   if(index > totNodes-1) 
   {
      printf("there are only %d nodes so node with index %d dosent exist!!",totNodes,index);
      return;
   }
   
   while(0U != index)
   {
      dum = dum->next;
   
      index--;
   }
   dispCurNode(*dum);
      
}


void dispCurNode(linkList node)
{
  printf("\n**********************************************\n");
   printf("%u   ",node.intd[roll]);
   printf("%s   ",node.name);
   printf("%u",node.intd[res]);
   printf("\n**********************************************\n");
}

linkList* addToStart(linkList * list)
{

   printf("\n-----------------in add to start -----------\n");

   linkList *node = NULL;
   unsigned int cnt =IRVRead();
   node = createNode();
   node->next = list;
   cnt++;
   IRVWrite(cnt);
   return node;


}


linkList* createNode()
{
   printf("\n----------------- Creating a node -----------\n");

   linkList *node = NULL;
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

   linkList *node    = NULL;
   linkList *slowPtr = list ;
   linkList *fastPtr = list;
   node = createNode();
   unsigned int cnt= IRVRead();
   cnt++;

   if(NULL == list)
   {
      list = node;
   }
   else
   {
      while(fastPtr->next && fastPtr->next->next)
      {   

         fastPtr = fastPtr->next->next;
         slowPtr = slowPtr->next;
      }

      dispCurNode(*slowPtr);

      node->next    = slowPtr->next;
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
      if(NULL == dum->next)
      {
         list = deleteFromStart(list);
      }
      else
      {
         
         dum->next->intd[res]  = 0U;
         dum->next->intd[roll] = 0U;
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
   linkList* dum = NULL;
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


linkList* deleteFromMiddle(linkList * list)
{
   linkList *fptr    = list;
   linkList *sptr    = list;
   linkList *dum     = NULL;
   linkList *lastptr = NULL;
   unsigned int cnt = IRVRead();
   
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
      if(sptr->next && (sptr->next->next  || (NULL == sptr->next->next)))
      {
         if(NULL == lastptr)
         {
         
           // puts("last pointer is null!!!!!");
            list = deleteFromStart(list);
         }
         else
         {
           // puts("last pointer is NOT null!!!!!");
            lastptr->next = sptr->next;
            free(sptr);
            sptr = NULL;
         }
      }
      else
      {
         list = deleteFromStart(list);

      }
      
      
   }
   IRVWrite(cnt);
   return list;
}

