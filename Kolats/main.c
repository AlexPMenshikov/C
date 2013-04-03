#include <stdio.h>
#include <stdlib.h>

int main()
{
 int n,i=1,b=2;
 scanf("%d",&n);
 if (n==1)
 {
     goto go;
 }
  /*  if(n==1)
    {
     n*=3;
     n++;
    }
*/
 while (n!=1)
 {
 go: if((n % 2)==0)
     {
        n/=2;
     }
     else
     {
         n*=3;
         n++;
     }
     i++;
 }
 printf("%d",i);
 return 0;
}
