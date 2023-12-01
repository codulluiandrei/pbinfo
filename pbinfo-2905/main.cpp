#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>

using namespace std;

ifstream fin("divizori4.in");
ofstream fout("divizori4.out");

int n, c, p, A[50001], e[40001], prime[40000], nrp;

int nr_div(int n)
{
    int rez = 1, p , d = 1;
    while(n > 1)
    {
        p = 0;
        while(n % prime[d] == 0)
            n /= prime[d], p ++;
        rez *= p + 1;
        d ++;
        if(prime[d] * prime[d] > n && n > 1)
            rez *= 2, n = 1;
    }
    return rez;
}



int main()
{
    e[0] = e[1] = 1;
    for(int i = 2 ; i * i <= 40000 ; i ++)
        if(e[i] == 0)
            for(int  j = 2 ; i * j <= 40000 ; j ++)
                e[i*j] = 1;
    for(int i = 2 ; i  <= 40000 ; i ++)
        if(e[i] == 0)
            prime[++nrp] = i;
    fin >> n >> c;
    assert(n <= 50000);
    for(int i = 1; i <= n ; i ++)
        fin >> A[i];
        
    fin >> p;
    int nrdx = nr_div(A[p]);
    if(c == 1)
        fout << nrdx << "
";
    else
    {
        sort(A+1, A+n+1, greater<int>());
        for(int i = 1 ; i <= n ; i ++)
            if(nr_div(A[i]) == nrdx)
                fout << A[i] << " ";
        fout << "
";
    }
    fin.close();
    fout.close();
    return 0;
}
