//A. Panaete 100
#include <bits/stdc++.h>
using namespace std;
ifstream f("secvmin.in");
ofstream g("secvmin.out");
const int N = 1000010;
int n,k,x[N],y[10],last[10];
int64_t sol;
int main()
{
    f>>n>>k;
    for(int i=1;i<=k;i++)y[i]=1000000010;
    for(int i=1; i<=n; i++)
    {
        int val;
        f>>val;
        if(val<y[k])
        {
            int p=1;
            while(val>y[p])p++;
            if(val<y[p])
            {
                int  q=k;
                while(q>p)
                {
                    y[q]=y[q-1];
                    q--;
                }
                y[p]=val;
            }
        }
        x[i]=val;
    }
    for(int i=1; i<=n; i++)
    {
        int cnt=n+1;
        for(int j=1; j<=k; j++)
        {
            if(x[i]==y[j])last[j]=i;
            cnt=min(cnt,last[j]);
        }
        sol+=cnt;
    }
    g<<sol;
    return 0;
}