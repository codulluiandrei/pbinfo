#include <bits/stdc++.h>
#define H 100003
using namespace std;

vector<pair<int,int>> T[H];
int n,i,x[H],p[32],c,v,w,j,h,C;
long long sol;

int main()
{
    cin >> n;
    for(i=1;i<=n;i++)
        cin >> x[i];
    sort(x+1,x+n+1);
    p[0]=1;
    for(i=1;i<=31;i++)
        p[i]=2*p[i-1];
    for(i=n;i;)
    {
        v=x[i];c=0;
        while(x[i]==v)
        {
            i--;c++;
        }
        if(v==(v&(-v)))
            sol+=1LL*c*(c-1)/2;
        for(j=31;;j--)
        {
            w=p[j]-v;
            if(w<=v)
                break;
            h=w%H;
            C=0;
            vector<pair<int,int>>::iterator it;
            for(it=T[h].begin();it!=T[h].end();it++)
                if(it->first==w)
                {
                    C=it->second;
                    break;
                }
            sol+=1LL*c*C;
        }
        h=v%H;
        T[h].push_back(make_pair(v,c));
    }
    cout << sol;
    return 0;
}
