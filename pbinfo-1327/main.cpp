#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("sirpie.in");
ofstream fout("sirpie.out");

int n, x[20],v[20];

int cmmdc(int a, int b)
{
    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void Afisare()
{
    for (int i = 1 ; i <= n ; i ++)
        fout << v[x[i]] << " ";
    fout << endl;
}

bool OK(int k)
{
    for(int i = 1; i < k ; i ++)
        if(x[i] == x[k])
            return false;
    if(k > 1)
        if(cmmdc(v[x[k]], v[x[k-1]]) != 1)
            return false;
    return true;
}

void back(int k)
{
    for(int i =1 ; i <= n ; i ++)
    {
        x[k] = i;
        if(OK(k))
            if(k == n)
                Afisare();
            else
                back(k+1);
    }
}

int main()
{
    fin >> n;
    for (int i = 1 ; i <= n ; i ++)
        fin >> v[i];
    for(int i = 1 ; i < n ; i ++)
        for(int j = i + 1 ; j <= n ; j ++)
            if(v[i] > v[j])
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
    back(1);
    return 0;
}
