#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ofstream fout("zet.out");
ifstream fin("zet.in");
int N , K, p;
long long V[15];
long long f(int n)
{
    if(V[n]>0)
        return V[n];
    V[n] = K * f(n - 1) - f(n - 2);
    return V[n];
}
int main()
{
    fin >> p;
    fin >> K;
    fin >> N;
    V[0] = 2;
    V[1] = K;
    if(p == 1)
        fout << f(2) << "\n";
    else
        fout << f(N) << "\n";
    fout.close();
    fin.close();
    return 0;
}