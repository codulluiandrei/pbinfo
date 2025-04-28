#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> w;
vector<string> v;
int maxi=0;
void fill(int k,int l,int p)
{
    w[k][l]=p;
    maxi=max(maxi,p);
    if(k+1<v.size())
    {
        if(l-1<v[k+1].size() && v[k+1][l-1]==' ' && w[k+1][l-1]==0)
            fill(k+1,l-1,++p),p--;
        if(l<v[k+1].size() && v[k+1][l]==' ' && w[k+1][l]==0)
            fill(k+1,l,++p),p--;
        if(l+1<v[k+1].size() && v[k+1][l+1]==' ' && w[k+1][l+1]==0)
            fill(k+1,l+1,++p),p--;
    }
}
int main()
{
    string s;
    int l,n;
    cin>>l>>n;
    cin.get();
    for(int i=1;i<=n;i++)
    {
        getline(cin,s);
        w.push_back(vector<int>(s.size(),0));
        v.push_back(s);
    }
    for(int i=0;i<v.size();i++)
        for(int j=0;j<v[i].size();j++)
            if(v[i][j]==' ' && w[i][j]==0)
                fill(i,j,1);
    cout<<maxi;
}