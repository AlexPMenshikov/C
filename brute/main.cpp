#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

int n;//����������� �������
int min_way = 32000; //����������� ����

int **cities; //������� ��������� �������
bool *visit;  //����� ��������� ������

void brute(int k, int v, int r)
{
	if(k == n)
	{
	    //������ �� �������� �����, ����� ��������� ����������
        if(r+cities[0][v] < min_way)// ���� ������� ���������� ������ ������, ������
        {
            min_way = r+cities[0][v];
        }
		return;
	}
	else
        for (int i=0; i<n; i++)
			{
			    //���� �� �� ���� � ������� � ��� = 0
				if ( (visit[i] == false) && (cities[v][i]!=0) )
				{
					visit[i] = true;							  //������� � ��

					brute(k+1, i, r+cities[v][i]);
					visit[i] = false;							  //������ �����
				}
			}
    return;
}


int main()
{
	ifstream in; //��������� ������ ifstream in ����� ������������ ��� ������
	in.open("input.txt");//������������ � ���������� �����
	in >> n; //��������� ���-�� �������
	//��������� ������� ���������
	cities = new int*[n];
	visit = new bool[n];
	for(int i = 0; i < n; i++)
	{
		visit[i] = false;//O������� ��� ������, ��� ������������
		cities[i] = new int[n];
		for(int j = 0; j < n; j++)
			in >> cities[i][j];
	}
	in.close();
    //������ ������� �������� ����������
	visit[0]=true;
	brute(1,0,0);
	cout << min_way << endl;//����������� ����
	//cout << endl;
	getch();
	return 0;
}
