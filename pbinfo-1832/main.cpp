#include <iostream>
#include <algorithm>
using namespace std;
int D[201],X[201],n;
unsigned long long s;
void afisare(int k)
{
    for(int i=1;i<=k;i++)
        cout<<D[X[i]]<<" ";
    cout<<"\n";
}
void back(int k, unsigned long long pp)
{
    for(int i=X[k-1]+1;i<=n && pp*D[i]<=s;i++)
    {
        X[k]=i;
        pp=pp*D[X[k]];
        if(pp<=s)
            if(pp==s) afisare(k);
            else back(k+1,pp);
        pp=pp/D[X[k]];
    }
}
int main()
{
    cin>>s;
    for(unsigned long long i=2;i*i<=s;i++)
        if(s%i==0)
        {
            D[++n]=i;
            if(i*i!=s)  D[++n]=s/i;
        }
    if(n==0) cout<<"NU EXISTA";
    else
    {
        sort(D+1,D+n+1);
        back(1,1);
    }
    return 0;
}