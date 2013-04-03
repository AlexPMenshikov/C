#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void swap(float *a, float *b)
{
    float temp=*a;
    *a=*b;
    *b=temp;
    FILE *f;
    f=fopen("input.txt","w");
    fprintf(f,"%f %f\n",temp,temp);
    fclose(f);
}

void quick_sort(float* arr[],int l, int r)
{
    int i = l,j = r;
    int x = arr[(l+r)/2]; //центральный элемент
    do
    {
        //процедура разделения
        while(arr[i] < x) ++i;
        while(arr[j] > x) --j;
        if (i <= j)
        {
            swap(&arr[i],&arr[j]);
            i++; j--;
        }

    }
    while(i<j);
    // рекурсивные вызовы, если есть, что сортировать
    if(l<j) quick_sort(arr, l, j);
    if(i<r) quick_sort(arr, i, r);
}

int main()
{
    int i=0,j=0;
    unsigned int size;
    double altime=0;
    printf("Enter size of array ");
    scanf("%d", &size);
    float arr[size];
    srand(time(NULL));
    do
    {
        arr[i]=rand()+rand()*2;//+rand()+rand();///*1000000+*/;//%200000;
        //printf("%f\n", arr[i]);
        i++;
    }
    while(i!=size);
    double start=GetTickCount();
    quick_sort(arr, 0, size);
    double finish=GetTickCount();
    altime=finish-start;
    for(i=0;i<size;i++)
    {
        //printf("%d=%.0f\n",i,arr[i]);
    }
    printf("%lf\n", altime);

    int ms,s,min;
    ms = (int)altime%1000;
    s = (((int)altime)/1000);
    min = (int)altime/100000;
    printf("%d min %d sec %d ms\n",min,s,ms);
    return 0;
}
