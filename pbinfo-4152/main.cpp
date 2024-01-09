#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

ifstream fin("lantmaxim1.in");
ofstream fout("lantmaxim1.out");

int n , A[105][105], x[105] , q, xmax[105], kmax = 0;

void afis(int x[], int k)
{
    for(int  i = 1 ; i <= k ; ++ i)
        fout << x[i] << " ";
    fout << "\n";
}

bool OK(int k)
{
	if(k == 1)
		return true;
    if(A[x[k-1]][x[k]] != 1)
        return 0;
    for(int i = 1 ; i < k ; ++i)
        if(x[k] == x[i])
            return 0;
    return 1;
}

void verifica(int k)
{
    if(k > kmax)
    {
        kmax = k;
        for(int i = 1; i <= k ; ++i)
            xmax[i] = x[i];
    }
}

void back(int k)
{
    for(int i = 1  ; i <= n ; ++i)
    {
        x[k] = i;
        if(OK(k))
        {
            if(x[k] == q)
                verifica(k);
            else
                back(k + 1);
        }
    }
}

int main()
{
    int i , j , m;
    fin >> n >> m;
    while(m > 0)
    {
        fin >> i >> j;
        A[i][j] = A[j][i] = 1;
        m --;
    }
    assert(fin >> q);
    back(1);
    afis(xmax , kmax);
    return 0;
}
