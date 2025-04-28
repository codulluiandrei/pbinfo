/// Solutie - Moca Andrei - 100p
#include <fstream>
using namespace std;
ifstream fin("afisaren.in");
ofstream fout("afisaren.out");
int n;
char c;
int main()
{
    fin >> n;
    if (n)
    {
        while (fin >> c)
            fout << c;
        fout << '\n';
        fin.close();
        for (int i = 2; i <= n; i++)
        {
            fin.open("afisaren.in");
            fin >> n;
            while (fin >> c)
                fout << c;
            fout << '\n';
            fin.close();
        }
    }
}