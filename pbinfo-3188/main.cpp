#include <bits/stdc++.h>
using namespace std;
ifstream fin("mate.in");
ofstream fout("mate.out");

int main()
{
    int n;
    unsigned long long t1=1,t0=0,t;
    fin>>n;
    fout<<t1<<" ";
    for(int i=2;i<=n;i++)
    {
        t=34*t1-t0+2;
        t0=t1;
        t1=t;
        fout<<t<<" ";
    }
    return 0;
}