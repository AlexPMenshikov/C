#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int str [99][99];
    int i,j,n,m,c=0;
    scanf("%d %d",&n,&m);
    //printf("%d %d\n",n,m);
    for (i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&str[i][j]);
        }
        //printf("\n");
    }
    /*for (i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d %d = %d\n",i,j,str[i][j]);
        }
        //printf("\n");
    }*/
    for (i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if (str[i][j]==1)
            {
                c++;
            }
        }
        //printf("\n");
    }
    printf("SYMBOL %d",c);
    getch();
    return 0;
}
