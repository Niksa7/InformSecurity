#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

string decode(string buffer)
{
    string new_buffer = buffer;
    string word;
    string resbuffer = "";
    stringstream ss;
    ss << buffer;
    while (ss >> word)
    {
        for (int i = 0; i < 3; i++)
        {
            word.insert(0, 1, word[word.length() - 1]);
            word.erase(word.length() - 1, 1);
        }
        resbuffer += word + " ";
    }
    return resbuffer;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    ofstream fout;
    fout.open("file.txt");
    fout << "ОСЕЛ РДИНАТАКОО СЕЛО КООРДИНАТА";
    fout.close();
    ifstream fin("file.txt");
    if (!fin.is_open())
        cout << "Невозможно открыть файл\n";
    else
    {
        ofstream nfout("newfile.txt");
        char buff[255];
        fin.getline(buff, 255);
        string buffer = string(buff);
        string resbuffer = decode(buffer);
        stringstream os(resbuffer);
        nfout << os.str();
    }
}