//Florentina Ungureanu
#include <bits/stdc++.h>
#define ull unsigned long long
#define nmaxi 1002
#define Nmaxi 1000020
using namespace std;
ifstream in("balon.in");
ofstream out("balon.out");
int c,n,m,k,d,x,y,p,b[nmaxi][nmaxi],a[nmaxi][nmaxi],s[Nmaxi];
ull vol,bb;
int main()
{
    int i,j;
    in>>c;
    in>>n>>m>>k>>p;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            in>>b[i][j];
    switch(c)
    {
    case 1:
    {
        for(int i=1; i<=p; ++i)
        {
            int xx, yy;
            in>>x>>y>>d;
            xx=x+d-1;
            yy=y+d-1;
            if(xx>n)xx=n;
            if(yy>m)yy=m;
            vol+=1ULL*(xx-x+1)*(yy-y+1);
        }
        out<<vol<<'\n';
        break;
    }
    case 2:
    {
        for(int l=1; l<=p; ++l)
        {
            int xx, yy;
            in>>x>>y>>d;
            a[x][y]++;
            xx=x+d-1;
            yy=y+d-1;
            if(xx>n)xx=n;
            if(yy>m)yy=m;
            a[x][yy+1]--;
            a[xx+1][y]--;
            a[xx+1][yy+1]++;
        }
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
                a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
            {
                bb+=a[i][j]/k;
                if(b[i][j]+a[i][j]%k>k)bb++;
            }
        out<<bb<<'\n';
        break;
    }
    case 3:
    {
        for(int l=1; l<=p; ++l)
        {
            int xx, yy;
            in>>x>>y>>d;
            a[x][y]++;
            xx=x+d-1;
            yy=y+d-1;
            if(xx>n)xx=n;
            if(yy>m)yy=m;
            a[x][yy+1]--;
            a[xx+1][y]--;
            a[xx+1][yy+1]++;
        }
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
                a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
            {
                b[i][j]+=a[i][j]%k;
                if(b[i][j]>k)b[i][j]-=k;
                s[b[i][j]]++;
            }
        int nivMax=k;
        while(nivMax&&!s[nivMax]) nivMax--;
        out<<nivMax<<' '<<s[nivMax]<<'\n';
    }
    }
}