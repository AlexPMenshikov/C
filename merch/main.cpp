#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <conio.h>

#define big 32000

using namespace std;

int n;//���������� �������

struct trip
{
	int **cities;//������� ��������� �������
	bool *visit; //����� ��������� ������
};

trip graph;

void read_graph()
{
    int i=0,j=0;
	ifstream in; //��������� ������ ifstream in ����� ������������ ��� ������
	in.open("input.txt"); //������������ � ���������� �����
	in >> n; //��������� ���-�� �������
	//cout << n << endl;
	//��������� ������� ���������
	graph.cities = new int*[n];//�������
	graph.visit = new bool[n];
	for(i = 0; i < n; i++)
	{
		graph.visit[i] = false;
		graph.cities[i] = new int[n];//���� �� �������
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
	graph.visit[0] = true;//��������� � 0 �������
	do
	{
		min=big;
		for(j=0;j<n;j++)
		{
		    //���� ������� ��� ���������� � ���� �� �� �����������
			if((graph.visit[j] == false) && (min > graph.cities[next_city][j]))
			{
			    //��������� � �� ��������� �������
				min = graph.cities[next_city][j];
				tmp=j;
			}
		}
		//��������� �������
        next_city=tmp;
        graph.visit[next_city]=true;
        //����������� �������� ����
        sum=sum+min;
        //cout << sum<<" "<<tmp<<" "<<graph.cities[next_city][tmp]<< endl;
        //��� ���� ����� ��������� � 0 �������
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
