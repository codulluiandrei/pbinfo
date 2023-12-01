#include<bits/stdc++.h>
using namespace std;

ifstream in("zzid.in");
ofstream out("zzid.out");

map<int,int>v;

int main()
{
   	int s=0,a,b,n,m,maxim=0,taietura;
    in>>n>>m;
    for(int i=1;i<=n;i++)
    {
        in>>a;
        for(int j=1;j<=a;j++)
        {
            in>>b;
            s+=b;
            if (s==m)
                continue;
            v[s]++;
            if(v[s]>maxim)
            {
                maxim=v[s];
                taietura=s;
            }
            if(v[s]==maxim && abs(m-taietura-taietura)>abs(m-s-s)){
                taietura=s;
            }
        }
        s=0;
    }
     out<<n-maxim<<" "<<abs(taietura-m+taietura);
    return 0;
}