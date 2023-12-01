#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>

using namespace std;

ifstream fin("potrivire.in");
ofstream fout("potrivire.out");

int n, A[100001], m, x;
int S = 0;
int v[100000];

int main()
{
    fin >> n;
    for(int i = 1; i <= n ; i ++)
    {
        fin >> A[i];
        assert(A[i] >= 0 && A[i] <= 9);
    }
    for(int i = 1 ; i <= n ; i ++)
        v[A[i]] = 1;
    for(int i = 1 ; i <= n - 1; i ++)
        v[A[i]*10 + A[i+1]] = 1;
    for(int i = 1 ; i <= n - 2; i ++)
        v[A[i]*100 + A[i+1]*10+A[i+2]] = 1;
    for(int i = 1 ; i <= n - 3; i ++)
        v[A[i]*1000 + A[i+1]*100+A[i+2]*10+A[i+3]] = 1;
    for(int i = 1 ; i <= n - 4; i ++)
        v[A[i]*10000 + A[i+1]*1000 + A[i+2]*100 + A[i+3]*10 +A[i+4]] = 1;
    
    for(fin >> m; m ; m --)
    {
        fin >> x;
        assert(x >= 0 && x <= 99999);
        if(v[x])
            S += x, v[x] = 0;
    }
    
    fout << S << "
";
    
    fin.close();
    fout.close();
    return 0;
}
