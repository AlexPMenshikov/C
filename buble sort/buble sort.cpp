 #include <stdio.h>
 #include <time.h>
 #include <windows.h>

 void swap (int *x, int *y)
{
     int temp;

     temp = *x;
	 *x = *y;
	 *y = temp;
}

float bubbleSort(int* arr, int size)
{
    int i, j;
    double start = GetTickCount();
    for(i=0; i < size-1; ++i) // i - номер прохода
    {
        for(j=0; j < size-1; ++j) // внутренний цикл прохода
        {
            if (arr[j + 1] < arr[j])
            {
                swap (&arr[j+1], &arr[j]);
            }
        }
    }
    //for (i=0; i<size; i++) { printf("%d ", arr[i]); }
    double finish = GetTickCount();
    return finish - start;
}


 int main ()
 {
 int i, size;

     printf("Write a size of your array...\n");
     scanf("%d", &size);
     scanf("%*c");

     srand(time(NULL));
     int arr[size];
     float time;
     int ms, s, min;
     //double start = GetTickCount();
     for (i=0; i < size; i++)
     {
         arr[i] = rand()%100000-9000;
         //printf("%d ", arr[i]);
     }
     //double finish = GetTickCount();
     printf("\nIs sorting...\n");
     time = bubbleSort(arr, size);
     printf("TIME %f",time);
     ms = (int)time%1000;
     s = (((int)time)/1000);//%100;
     min = (int)time/100000;
     //printf("\nTime of Bubble Sort:  %f", bubbleSort(arr, size));
     printf("\nTime of Bubble Sort:  %d min %d s %d ms", min,s,ms);
 scanf("%*c");

 return 0;
}

//Элементы                  Тики                    Секунды
//30000                     16505.0000              ~16
//30000                     14446.0000              ~14
//30000                     15225.0000              ~15
