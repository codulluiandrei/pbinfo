#include<bits/stdc++.h>
using namespace std;
ifstream in("identice3.in");
ofstream out("identice3.out");
#define Nmax 1005
char a[Nmax][Nmax],a1[Nmax][Nmax];
char opus[]="10";
int t0[Nmax][Nmax],st0[Nmax],val0[Nmax],vf0,n,d;
int t1[Nmax][Nmax],st1[Nmax],val1[Nmax],vf1;
long long sum0,sum1;
int sol0,p0[Nmax],M0[Nmax][Nmax];
int sol1,p1[Nmax],M1[Nmax][Nmax];
int test;
void read()
{
    in>>test>>n>>d; in.get();
    for(int i=1;i<=n;++i)
    {
        in.getline(a[i]+1,n+2);
        for(int j=1;j<=n;++j) a1[i][j]=opus[a[i][j]-'0'];
    }
    in.close();
}
void suma0()
{
    for(int i=1;i<vf0;i++)
         sum0+=val0[i]*st0[i];
}
void suma1()
{
    for(int i=1;i<vf1;i++)
         sum1+=val1[i]*st1[i];
}
void solve0()
{
    int m;
    for(int j=1;j<=n;j++)
    {
        vf0=0;
        for(int i=1;i<=n;i++)
            {
                if(a[i][j]=='0')
                    t0[i][j+1]=1+t0[i][j];
                m=1;
                while(vf0>0&&st0[vf0]>=t0[i][j+1]) {m+=val0[vf0]; vf0--;}
                vf0++; st0[vf0]=t0[i][j+1]; val0[vf0]=m; sum0+=val0[vf0]*st0[vf0];
                suma0();
            }
    }
    //out<<sum0;
}
void solve1()
{
    int m;
    for(int j=1;j<=n;j++)
    {
        vf1=0;
        for(int i=1;i<=n;i++)
            {
                if(a[i][j]=='1')
                    t1[i][j+1]=1+t1[i][j];
                m=1;
                while(vf1>0&&st1[vf1]>=t1[i][j+1]) {m+=val1[vf1]; vf1--;}
                vf1++; st1[vf1]=t1[i][j+1]; val1[vf1]=m; sum1+=val1[vf1]*st1[vf1];
                suma1();
            }
    }
    //out<<sum1;
}
void R0()
{
    int ok=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            M0[i][j]+=M0[i-1][j];
            p0[j]=p0[j-1]+M0[i][j];
            int t=(p0[j]&1);
            if(i>n-d+1||j>n-d+1)
            {
                if(t!=(a[i][j]-'0')) ok=0;
            }
            else if(t!=(a[i][j]-'0'))
            {
                ++sol0;
                M0[i][j]++;
                M0[i+d][j]--;
                M0[i][j+d]--;
                M0[i+d][j+d]++;
                ++p0[j];
            }
        }
    if(!ok) sol0=-1;
}
void R1()
{
    int ok=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            M1[i][j]+=M1[i-1][j];
            p1[j]=p1[j-1]+M1[i][j];
            int t=(p1[j]&1);
            if(i>n-d+1||j>n-d+1)
            {
                if(t!=(a1[i][j]-'0')) ok=0;
            }
            else if(t!=(a1[i][j]-'0'))
            {
                ++sol1;
                M1[i][j]++;
                M1[i+d][j]--;
                M1[i][j+d]--;
                M1[i+d][j+d]++;
                ++p1[j];
            }
        }
    if(!ok) sol1=-1;
}
int main()
{
    read();
    if(test==1)
    {
        solve0();solve1();out<<sum0+sum1<<'\n';
    }
    else
        {
         R0();R1();
         int rx=min(sol0,sol1),ry=max(sol0,sol1); if(rx==-1) rx=ry;
         out<<rx<<'\n';
        }
    out.close();
    return 0;
}