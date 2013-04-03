#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <conio.h>

#define big 32000

using namespace std;

int n;//Количество городов

struct trip
{
	int **cities;//Матрица смежности городов
	bool *visit; //Метка посещения города
};

trip graph;

void read_graph()
{
    int i=0,j=0;
	ifstream in; //Экземпляр класса ifstream in будем использовать для чтения
	in.open("input.txt"); //Присоединяем к текстовому файлу
	in >> n; //Считываем кол-во городов
	//cout << n << endl;
	//Считываем матрицу смежности
	graph.cities = new int*[n];//Вершина
	graph.visit = new bool[n];
	for(i = 0; i < n; i++)
	{
		graph.visit[i] = false;
		graph.cities[i] = new int[n];//Путь от вершины
		for(j = 0; j < n; j++)
			in >> graph.cities[i][j];
	}
	in.close();
}

int main()
{
	int min,i=0,j=0;
	int tmp,next_city=0;
	int sum=0,k=0;
	read_graph();
	graph.visit[0] = true;//Находимся в 0 вершине
	do
	{
		min=big;
		for(j=0;j<n;j++)
		{
		    //Если вершина ещё непосещена и путь до неё минимальный
			if((graph.visit[j] == false) && (min > graph.cities[next_city][j]))
			{
			    //Принимаем её за локальный минимум
				min = graph.cities[next_city][j];
				tmp=j;
			}
		}
		//Локальный минимум
        next_city=tmp;
        graph.visit[next_city]=true;
        //Увеличиваем итоговый путь
        sum=sum+min;
        //cout << sum<<" "<<tmp<<" "<<graph.cities[next_city][tmp]<< endl;
        //Для того чтобы вернуться в 0 вершину
        if(k==(n-2))
            {
				graph.visit[0] = false;
			}
        k++;
	}
    while (next_city!=0);
    //cout << endl;
	cout << sum << endl;
	getch();
	return 0;
}
