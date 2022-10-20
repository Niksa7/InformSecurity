#include <iostream> 
#include <random> 
#include <string> 

using namespace std;

int random(int k)
{
	int rnd = rand() % k;
	return rnd;
}

void Print_Matrix(string*** A, int n, int m)//вывод матрицы на экран 
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "[" << A[i][j][0] << "," << A[i][j][1] << "]";
		}
		cout << "\n";
	}
}

bool check_Matrix(string*** A, int* LS, int* LO, int n, int m)
{
	bool ok = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((LS[i] < LO[j] && stoi(A[i][j][0]) == 1) || (LS[i] > LO[j] && stoi(A[i][j][1]) == 1))//stoi - преобразование численных строк в целые числа
			{
				ok = false;
				cout << "\nМатрица не прошла проверку на cубъекте " << i << " и объекте " << j;
			}
		}
	}
	return ok;
}

string*** fill_Matrix(string*** A, int* LS, int* LO, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (LS[i] >= LO[j])
				A[i][j][0] = to_string(1);
			else
				A[i][j][0] = to_string(0);
			if (LS[i] <= LO[j])
				A[i][j][1] = to_string(1);
			else
				A[i][j][1] = to_string(0);
		}
	}
	return A;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int n, m;
	n = 3;
	m = 5;

	string*** A = new string **[n];//матрица доступа
	for (int i = 0; i < n; i++)
	{
		A[i] = new string * [m];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			A[i][j] = new string[2];
		}
	int* LS = new int[n], * LO = new int[m];//LS[i] – значение уровня допуска субъекта si; LO[j] – значение уровня секретности объекта oj


	for (int i = 0; i < n; i++)
	{
		LS[i] = random(9);//случайные числа 
	}
	for (int i = 0; i < m; i++)
	{
		LO[i] = random(9);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int z = 0; z < 2; z++)
			{
				A[i][j][z] = to_string(random(2));
			}

	string*** A1 = new string * *[n];
	A1 = fill_Matrix(A, LS, LO, n, m);
	Print_Matrix(A1, n, m);
	if (check_Matrix(A, LS, LO, n, m))
		cout << "\nДанная матрица прошла проверку";
	else
		cout << "\nДанная матрица не прошла проверку";
}