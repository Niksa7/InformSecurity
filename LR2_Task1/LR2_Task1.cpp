#include <iostream>
#include <fstream>

using namespace std;

void decode()
{
	ifstream fin("input.txt");
	int n, i = 0;
	fin >> n;
	int flag = 0;
	int comb = n * n;
	int mas[100];
	ofstream fout("output.txt");
	for (i = 0; i < n; i++)
	{
		fin >> mas[i];
	}
	for (i = 0; i < n; i++)
	{
		if (mas[i] % n == 0)
		{
			flag = 1;
			fout << "YES\n" << mas[i] << "\n" << comb;
			break;
		}
		for (int j = i + 1; j < n - i; j++)
		{
			if ((mas[i] + mas[j]) % n == 0)
			{
				flag = 1;
				fout << "YES\n" << mas[i] << "\n" << comb;
				break;
			}
		}
	}
	if (flag == 0)
	{
		fout << "NO\n";
		fout.close();
	}
}

int main()
{
	decode();
}