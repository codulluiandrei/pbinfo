#include <bits/stdc++.h>
using namespace std;
unsigned long long fact(int n)
{
    unsigned long long p=1,i;
    for(i=1;i<=n;i++)
        p=p*i;
    return p;
}
int n,i;
int main()
{
    ifstream f("triunghiul.in");
    ofstream g("triunghiul.out");
    f>>n;
    for(i=0;i<=n;i++)
    {
        g<<fact(n)/(fact(i)*fact(n-i))<<" ";
    }
    return 0;
}