/** @file Prim-s-algorithm.cpp */
#include <iostream>
using namespace std;

int main()
{
	//setlocale(LC_ALL, "RUS");

	int N; /*! Vvod kolichestva uzlov v grafe */
	cout << "Vvedite kolichestvo uzlov v grafe >> "; cin >> N;
	/// Sozdaem massiv so stoimost'ju reber v grafe 
	int **cost = new int*[N];
	for (int i = 0; i < N; i++)
	{
		cost[i] = new int[N];
	}
	/// Sozdaem massiv, v kotoryj budem pomeshhat' poseshhennye rebra
	int *visited = new int[N];
	/// Sozdaem massiv, v kotoryj budem zanosit' vershiny, obrazujushhie min. ostovnoe derevo
	int *path = new int[N];
	int path_idx = 0;
	
	cout << "Vvedite rasstojanie mezhdu uzlami:" << endl; /*! Vvod rasstojanija mezhdu uzlami */
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)
			{
				cost[i][j] = 0;
			}

			if (i < j)
			{
				cout << "Rasstojanie mezhdu uzlom " << i + 1 << " i " << j + 1 << " >> ";
				cin >> cost[i][j];
				cost[j][i] = cost[i][j];
			}
		}
	}
	/// Vyvod matricy sezhnosti
	cout << "\nMatrica smezhnosti: \n" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << cost[i][j] << "\t ";
			if (cost[i][j] == 0)
			{
				cost[i][j] = INT_MAX; 
			}
		}
		cout << endl << endl;
	}
	
	visited[0] = 1;
	for (int i = 1; i < N; i++) 
	{
		visited[i] = 0;
	}	
	/// Realizacija algoritma Prima 
	int a, b, u, v, idx = 1, min, mincost = 0;
	cout << "Pary vershin, kotorye svjazyvaet minimal'noe ostovnoe derevo: ";
	while (idx < N)
	{
		min = INT_MAX;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (cost[i][j] < min)
				{
					if (visited[i] != 0)
					{
						min = cost[i][j];
						a = u = i;
						b = v = j;
					}
				}
			}
		}
		
		if (visited[a] == 0 || visited[b] == 0)
		{
			path[path_idx] = b;
			path_idx++;
			cout << endl << idx++ << ") " << "Stoimost' rebra mezhdu " << a + 1 << " i " << b + 1 << " ravna " <<  min; /*! Vyvod par vershin, kotorye obrazujut min. ostovnoe derevo */			
			mincost += min;
			visited[b] = 1;
		}

		cost[a][b] = cost[b][a] = INT_MAX;
	}
	
	cout << "\n\nMinimal'noe ostovnoe derevo: "; /*! Vyvod min. ostovnogo dereva */
	cout << 1 << " --> ";
	for (int i = 0; i < N - 1; i++)
	{
		cout << path[i] + 1;
		if (i < N - 2) cout << " --> ";
	}

	cout << "\nMinimal'naja stoimost' ostovnogo dereva: " << mincost; /*! Vyvod min. stoimosti ostovnogo dereva*/
	cout << endl;

	system("pause");
	return 0;	
}