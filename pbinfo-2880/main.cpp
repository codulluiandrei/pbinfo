#include<bits/stdc++.h>
using namespace std;

ifstream in("gradinita.in");
ofstream out("gradinita.out");

bool ciur[100001];
int n,x,v[100001],nr;

int sum_cif_impare(int x)
{
    int nrc=0,p=1,s=0;
    while(p<=x)
    {
        p*=10;
        nrc++;
    }
    if(nrc%2==0)
        x/=10;
    while(x>0)
    {
        s+=x%10;
        x/=100;
    }
    return s;
}

void init()
{
    int i;
    ciur[0]=ciur[1]=1;
    for(int i=4;i<=100001;i+=2)
        ciur[i]=1;
    for(i=3;i*i<=100001;i+=2)
        if(ciur[i]==0)
            for(int j=i*i;j<=100001;j+=2*i)
                ciur[j]=1;
}

int main()
{
    init();
    int k;
    in>>n>>k;
    if(k==1)
    {
        out<<"Toti copiii sunt obraznici!";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        in>>x;
        if(ciur[x] && ciur[sum_cif_impare(x)])
            v[++nr]=x;
    }
    if(nr==0)
        out<<"Toti copiii sunt obraznici!";
    else
        for(int i=1;i<=nr;i++)
            if(i%k!=0)
                out<<v[i]<<" ";
        return 0;
}
