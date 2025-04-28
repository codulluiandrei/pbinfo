#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> v,w;
    string s,ss;
    int n,p;
    cin>>n;
    cin.get();
    for(int i=1;i<=n;i++)
    {
        getline(cin,s);
        v.push_back(s);
    }
    while(v.size())
    for(int i=0;i<v.size();i++)
    {
        s=v[i];
        p=s.find(' ');
        if(p==-1)
            ss+=s,ss+=' ',s="",v[i]=s;
        if(v[i]=="")
            v.erase(v.begin()+i),i--;
        else
        {
            for(int j=0;j<=p;j++)
            ss+=s[j];
            s.erase(0,p+1);
            v[i]=s;
        }
    }
    cout<<ss;
    return 0;
}