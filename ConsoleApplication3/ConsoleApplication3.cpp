#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#pragma hdrstop                  // Предоставляет дополнительный элемент управления по именам файлов предварительной компиляции и над местоположением на котором сохраняется состояние компиляции


using namespace std;

int power(int a, int b, int n) {// a^b mod n
    int tmp = a;
    int sum = tmp;
    for (int i = 1;i < b;i++) {
        for (int j = 1;j < a;j++) {
            sum += tmp;
            if (sum >= n) {
                sum -= n;
            }
        }
        tmp = sum;
    }
    return tmp;
}

int mul(int a, int b, int n) {// a*b mod n
    int sum = 0;

    for (int i = 0;i < b;i++) {
        sum += a;

        if (sum >= n) {
            sum -= n;
        }
    }

    return sum;
}


void crypt(int p, int g, int x, string inFileName, string outFileName) {

    setlocale(LC_ALL, "Russian");
    ifstream inf(inFileName.c_str());   //Формирует массив строк  И возвращает указатель на него.
    ofstream outf(outFileName.c_str());
    int y = power(g, x, p);
    printf("Открытый ключ (p,g,y)=", setlocale(LC_ALL, "Russian"));
    cout << "" << "(" << p << "," << g << "," << y << ")" << endl;
    cout << "Закрытый ключ x=" << x << endl;
    cout << "Введите текст который необходимо зашифровать\n";


    while (inf.good()) {
        int m = inf.get();
        if (m > 0) {
            cout << (char)m;

            int k = rand() % (p - 2) + 1; // 1 < k < (p-1)
            int a = power(g, k, p);
            int b = mul(power(y, k, p), m, p);
            outf << a << " " << b << " ";
        }
    }

    cout << endl;

    inf.close();
    outf.close();
}

void decrypt(int p, int x, string inFileName, string outFileName) {

    ifstream inf(inFileName.c_str());
    ofstream outf(outFileName.c_str());
    setlocale(LC_ALL, "Russian");

    cout << "\nДешифрованый текст:" << endl;

    while (inf.good()) {
        int a = 0;
        int b = 0;
        inf >> a;
        inf >> b;

        if (a != 0 && b != 0) {


            int deM = mul(b, power(a, p - 1 - x, p), p);// m=b*(a^x)^(-1)mod p =b*a^(p-1-x)mod p 
            char m = static_cast<char>(deM);
            outf << m;
            cout << m;
        }
    }

    cout << endl;

    inf.close();
    outf.close();
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    int p = 0, g = 0, x = 0;
    cout << "Введите p,g,x\n";
    cin >> p >> g >> x;
    crypt(p, g, x, "input.txt", "outsh.txt");
    decrypt(p, x, "outsh.txt", "outdesh.txt");
    system("pause");
    return 0;
}