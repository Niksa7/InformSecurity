#include <iostream>
#include <fstream>

using namespace std;

int digits(int num)
{
    int  i = 0;
    for (; num > 0; i++) {
        num /= 10;
    }
    return i;
}

int simple(int num)
{
    for (int i = 2;i <= sqrt(num);i++)
        if (num % i == 0)
            return 0;
    return 1;
}

int composition(int num)
{
    int res = 1;

    while (num != 0)
    {
        res = res * (num % 10);
        num = num / 10;
    }

    return res;
}


void task4()
{
    ofstream output("code.txt");
    int n = 9999;
    int i = 0;
    int k = 0;
    while (n - i > 0)
    {
        if (n - i >= 0 && digits(n - i) == 4 && simple(n - i) == 1 && composition(n - i) == 243)
        {
            output << "Перестановки: " << n - i << endl;
            k++;
        }

        i++;
    }
    output << "Количество: " << k;
}

int main()
{
    task4();
}