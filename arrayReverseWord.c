#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define messege(x) printf("%s\n",x)
#define messege1(x) printf("%s ",x)
int i = -1;

char** input()
{
   static char **ip = NULL, ch;
   int ix=0,j=0;
   while((ch = getchar()) != '\n')
   {
      if(ch == ' ' || ch == ',' || i == -1)
      {
        if(i!= -1 && ip!= NULL && ip[i]!= NULL)
        {
           ip[i] = (char*)realloc(ip[i],(j+1)*sizeof(char));
           ip[i][j] = '\0';
           j=0;
           
        }
         i++;
         ip = (char**)realloc(ip,(i+1)*sizeof(char**));
         if(ip == NULL) messege("realloc failed");
         //messege("-1 or spl char i++");
         if(i==0 && ch != ' ' && ch!= ',')
         {
            ip[i] = (char*)realloc(ip[i],(j+1)*sizeof(char));
            ip[i][j] = ch;
            j++;
                  
         }
      }
      else{
      ip[i] = (char*)realloc(ip[i],(j+1)*sizeof(char));
      ip[i][j] = ch;
      j++;
      }
      
   }
   ip[i] = (char*)realloc(ip[i],(j+1)*sizeof(char));
      ip[i][j] = '\0';
      
      
      
      
   return ip;
}

char ** logic(char** ip)
{
   char *temp;   
   int ix=0,iy =i;
   for(ix =0;ix<=iy;ix++,iy--)
   {
      temp= ip[ix];
      ip[ix]= ip[iy];
      ip[iy]=  temp;
   }
   return ip;
   
}
void output(char **array)
{
   int ix;
      for(ix=0 ;ix<=i;ix++)
      {
         messege1(array[ix]);
              free((void*)array[ix]);
      }
      
      free((void*)array);
}
int main()
{
   char **array = NULL;
   int ix = 0;
   messege("enter string below");
   
 
 output(logic(input()));
  
                 


   
}