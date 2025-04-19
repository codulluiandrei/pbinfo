#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> result,rnk,player,ranked;
    int n,r,x;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        ranked.push_back(x);
    }
    cin>>r;
    for(int i=0; i<r; i++)
    {
        cin>>x;
        player.push_back(x);
    }
    int l=player.size();
    int d=ranked.size();
    int y=1;
    rnk.push_back(y);
    for(int i=1; i<d; i++)
    {
        if(ranked[i-1]>ranked[i])
            y++;
        rnk.push_back(y);
    }
    for(int i=0; i<l; i++)
    {
        int x=player[i];
        int st=0,dr=ranked.size()-1;
        if(x<ranked[dr])
            result.push_back(rnk[dr]+1);
        else if(x>ranked[0])
            result.push_back(1);
        else
        {
            while(st<=dr)
            {
                int mij=(st+dr)/2;
                if(x>=ranked[mij])dr=mij-1;
                else st=mij+1;
            }
            result.push_back(rnk[st]);
        }
    }
    for(int i=0;i<r;i++)
        cout<<result[i]<<endl;
    return 0;
}