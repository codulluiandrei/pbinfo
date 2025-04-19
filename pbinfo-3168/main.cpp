#include <fstream>
#include <iostream>
using namespace std;
int x[10], n, m;
ofstream fout("pm.out");
ifstream fin("pm.in");
int maxim(int k)
{
    int i , z = 0;
    for(i = 1 ; i <= k ; i++)
        z = max(x[i] , z);
    return z;
}
void scrie(ostream & out)
{
    int z = maxim(n);
    for(int i = 1 ; i <= z ; i ++)
    {
        for(int j = 1 ; j <= n ; j ++)
            if(x[j] == i)
                out << j;
        out << "*";
    }
    out << '\n';
}
void back(int k)
{
    int s = maxim(k - 1);
    if(s > m)
        return;
    for(int i = 1; i <= s + 1 ; i++)
    {
        x[k] = i;
        if(k == n)
        {
            if(maxim(n) == m)
                scrie(fout);
        }
        else
            back(k + 1);
    }
}
int main()
{
    fin >> n >> m;
    x[1] = 1;
    back( 2 );
return 0;}