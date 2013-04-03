#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

int n;//Колличество городов
int min_way = 32000; //минимальный путь

int **cities; //Матрица смежности городов
bool *visit;  //Метка посещения города

void brute(int k, int v, int r)
{
	if(k == n)
	{
	    //пришли на исходное место, можем посчитать расстояние
        if(r+cities[0][v] < min_way)// если прошлое расстояние больше нового, меняем
        {
            min_way = r+cities[0][v];
        }
		return;
	}
	else
        for (int i=0; i<n; i++)
			{
			    //Если мы не были в вершине и она = 0
				if ( (visit[i] == false) && (cities[v][i]!=0) )
				{
					visit[i] = true;							  //заходим в неё

					brute(k+1, i, r+cities[v][i]);
					visit[i] = false;							  //шагаем назад
				}
			}
    return;
}


int main()
{
	ifstream in; //Экземпляр класса ifstream in будем использовать для чтения
	in.open("input.txt");//Присоединяем к текстовому файлу
	in >> n; //Считываем кол-во городов
	//Считываем матрицу смежности
	cities = new int*[n];
	visit = new bool[n];
	for(int i = 0; i < n; i++)
	{
		visit[i] = false;//Oтмечаем все города, как непосещённые
		cities[i] = new int[n];
		for(int j = 0; j < n; j++)
			in >> cities[i][j];
	}
	in.close();
    //первую вершину отмечаем посещённой
	visit[0]=true;
	brute(1,0,0);
	cout << min_way << endl;//Минимальный путь
	//cout << endl;
	getch();
	return 0;
}
