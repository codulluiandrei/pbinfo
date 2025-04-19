#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("low_memory.in");
ofstream fout("low_memory.out");
void afisare(int n)
{
    if(n)
    {
        long long x;
        fin >> x;
        afisare(n-1);
        fout << x << " ";
    }
}
int main()
{
    int n;
    fin >> n;
    afisare(n);
    return 0;
}