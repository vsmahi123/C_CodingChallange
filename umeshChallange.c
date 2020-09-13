#include<stdio.h>
#include<stdlib.h>
#define NoOFElem 6U
#define DEBUG 0
#if DEBUG == 1
    #define deb(x,...) printf(x,##__VA_ARGS__)
#else
    #define deb(x,...)
#endif
typedef struct 
{
    unsigned int Num;
    unsigned int Index
    /* data */
}NumData_t;

NumData_t FindHighest(unsigned int array[NoOFElem])
{
    NumData_t Numb = {0,0};
    unsigned int i=0;
    for(i=0;i<NoOFElem;i++)
    {
        if(Numb.Num <= array[i])
        {
            Numb.Num = array[i];
            Numb.Index = i;

        }

    }
    return Numb;
}
NumData_t FindSecHighestLeft(unsigned int array[NoOFElem],unsigned int hiNumPos)
{
    NumData_t Numb = {0,0};
    unsigned int i=0;
    for(i=0;i<hiNumPos;i++)
    {
        if(Numb.Num <= array[i])
        {
            Numb.Num = array[i];
            Numb.Index = i;

        }

    }
    return Numb;

}

NumData_t FindSecHighestRight(unsigned int array[NoOFElem],unsigned int hiNumPos)
{
    NumData_t Numb = {0,0};
    unsigned int i=0;
    for(i=hiNumPos+1;i<NoOFElem;i++)
    {
        if(Numb.Num <= array[i])
        {
            Numb.Num = array[i];
            Numb.Index = i;

        }

    }
    return Numb;

}
void takeInput(unsigned int array[NoOFElem])
{

   unsigned int i=0;
   for(i=0;i<NoOFElem;i++)
   {
       printf("enter element no [%u]->",i);
       scanf("%u",array+i);
       printf("\n");
   }
}
unsigned int FinalLogic(NumData_t Highest,
                        NumData_t LHighest,
                        NumData_t RHighest)
{
    unsigned int res,a,b,noOfElOnLeft = 0,noOfElOnRight = 0;
    noOfElOnLeft = Highest.Index;
    noOfElOnRight = (NoOFElem-1) - Highest.Index;
  if (Highest.Index == (NoOFElem-1))
  {
    res = (((Highest.Index)*(LHighest.Num)) + Highest.Num);
  }
  else if(Highest.Index == 0)
  {
      deb("highest no.on right %u \n",RHighest.Num);
    res = (((NoOFElem-1)*(RHighest.Num)) + Highest.Num);
  }
  else
  {
    a = (LHighest.Num*noOfElOnLeft)+ (Highest.Num*(noOfElOnRight +1));
    b = (RHighest.Num*noOfElOnRight)+ (Highest.Num*(noOfElOnLeft +1));
    deb("elem left = %u\n",noOfElOnLeft);
    deb("elem Right = %u\n",noOfElOnRight);
    deb(" 1 .   %u\n",a); 
    deb(" 2 .   %u\n",b);

    res = a>b?b:a;
  }
  
   return res;
}
 

int main()
{
    unsigned int ans, array[NoOFElem]= {0,};
    NumData_t highestNum = {0,0},leftHigh ={0,0},rightHigh = {0,0};

    takeInput(array);   
    highestNum = FindHighest(array);
    leftHigh = FindSecHighestLeft(array,highestNum.Index);
    rightHigh = FindSecHighestRight(array,highestNum.Index);
    deb("Highest num is  %u  At index  %u \n",highestNum.Num,highestNum.Index);
    deb("2nd Highest num left is  %u  At index  %u \n",leftHigh.Num,leftHigh.Index);
    deb("2nd Highest num Right is  %u  At index  %u \n",rightHigh.Num,rightHigh.Index);
    ans =FinalLogic(highestNum,leftHigh,rightHigh);
  printf("\n total no of banners length ==> %d\n ",ans );
}