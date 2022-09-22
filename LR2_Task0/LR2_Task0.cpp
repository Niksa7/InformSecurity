#include <iostream>
#include <fstream>

using namespace std;

//REL

void REL(string buf)
{
    ofstream fout("output.txt");
    char letter = buf[0];
    int count = 1;
    for (int i = 1; i < buf.length();i++)
    {
        if (letter == buf[i])
        {
            count++;
        }
        else
            if (count == 1)
            {
                fout << letter;
                letter = buf[i];
                count = 1;
            }
            else
            {
                fout << count << letter;
                letter = buf[i];
                count = 1;
            }
    }
    if (count == 1)
        fout << letter;
    else
        fout << count << letter;

}

int main()
{
    ifstream fin("input.txt");
    if (!fin.is_open())
    {
        cout << "Невозможно открыть файл\n";
    }
    else
    {
        string buffer;
        fin >> buffer;
        REL(buffer);
    }
}