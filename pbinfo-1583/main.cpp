#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("2prim.in");
ofstream fout("2prim.out");
int n,x,i,t,k,j;
int prim(int n)
{
    int i;
    if(n<2)
        return 0;
    if(n==2)
        return 1;
    if(n%2==0)
        return 0;
    for(i=2; i<=n/2+1; i++)
        if(n%i==0)
            return 0;
    return 1;
}
int main()
{
    fin>>n;
    for (i=1; i<=n; i++) {
        fin>>x;
        if (prim(x%100)) k++;
    }
    fout<<k;
    cout<<k;
    return 0;
}