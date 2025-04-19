#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("pozitiiconsecutive.in");
ofstream fout("pozitiiconsecutive.out");
int main()
{
    int a , b , c;
    fin >> b >> c;
    fin.close();
    fout << c << " " << b << " ";
    while(b)
    {
        a = 2 * b - c + 2;
        fout << a << " ";
        c = b;
        b = a;
    }
    fout.close();
    return 0;
}