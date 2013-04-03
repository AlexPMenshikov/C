#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

void clean (int n, int m, int size, int *arr[size][size])
{
    int tmps=size, i, j;

    for (j=0; j<tmps; j++)
        {
            arr[n][j]=0;
        }

    for (i=n; i<size-1 ;i++)
    {
        for (j=0; j<tmps; j++)
        {
            arr[i][j]=arr[i+1][j];
        }
    }

    n--;

    for (i=0; i<tmps; i++)
        {
            arr[i][m]=0;
        }
    for (i=0; i<size-1 ;i++)
    {
        for (j=m; j<tmps; j++)
        {
            arr[i][j]=arr[i][j+1];
        }
    }

    m--;

    for(i=0;i<tmps;i++)
    {
        arr[tmps][i]=0;
        arr[tmps][i-tmps]=0;
    }

    for (i=0; i<size-1;i++)
    {
        for (j=0; j<tmps-1; j++)
        {
        printf("%d ", arr[i][j]);
        }
    printf("\n");
    }
//return size;
}

int main ()
{
    int i, j, size;

    printf("Write a size of your array...\n");
    scanf("%d", &size);
    //scanf("%*c");

    srand(time(NULL));

    int arr[size][size], n, m;

    for (i=0; i<size;i++)
    {
        for (j=0; j<size; j++)
        {
            arr[i][j]= rand()%10;
            printf("%d ", arr[i][j]);
        }
    printf("\n");
    }

    scanf("%d", &n);
    scanf("%d", &m);
    clean (n, m, size, arr);
    size--;
    printf("\n");
    for (i=0; i<size;i++)
    {
        for (j=0; j<size; j++)
        {
            printf("%d ", arr[i][j]);
        }
    printf("\n");
    }
    //getch();
    return 0;
}
