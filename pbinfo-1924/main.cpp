// Popa Bogdan Ioan, Colegiul National Aurel Vlaicu Orastie, clasa a 10-a
#include <bits/stdc++.h>
#define nmax 100001
#define Smax 1000
using namespace std;
ifstream fin("qstiva.in");
ofstream fout("qstiva.out");
int n,x,i,t,Q,j;
bitset <Smax+2> dp[nmax];
int main()
{
    dp[0][0]=1;
    for(fin>>Q;Q;Q--)
    {
        fin>>t;
        if(t==1)
        {
            fin>>x;
            n++;
            dp[n].reset();
            for(i=Smax-x+1;i<=Smax;i++)
                dp[n][i]=dp[n-1][i];
            for(i=Smax-x;i>=0;i--)
                if(dp[n-1][i])
                    dp[n][i+x]=dp[n][i]=1;
        }
        if(t==2)
            n--;
        if(t==3)
        {
            fin>>x;
            fout<<dp[n][x]<<"\n";
        }
    }
    return 0;
}