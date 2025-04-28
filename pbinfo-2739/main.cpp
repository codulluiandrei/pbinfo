#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> w;
    int lmax=1,l=1,k=0,ap=0;
    string s,ss;
    getline(cin,s);
    while(s[k]==' ')
        k++;
    for(int i=k;i<s.size();i++)
    {
        if(s[i]==' ')
            ap++;
        else
        if(ap)
            w.push_back(ap),ap=0;
    }
    vector<string> v,z;
    istringstream b(s);
    for(string w;b>>w;)
        v.push_back(w);
    for(int i=1;i<v.size();i++)
    {
        s=v[i-1];
        if(s[s.size()-1]==v[i][0])
            l++;
        else
        {
            lmax=max(lmax,l);
            l=1;
        }
    }
    if(lmax==1)
    {
        cout<<-1;
        return 0;
    }
    z=v;
    ap=0;
    for(int i=0;i<z.size();i++)
    {
        ss=z[i];
        for(int j=1;j<=w[ap];j++)
            ss+=' ';
        z[i]=ss;
        ap++;
        if(ap==w.size())
            break;
    }
    l=1;
    for(int i=1;i<v.size();i++)
    {
        s=v[i-1];
        if(s[s.size()-1]==v[i][0])
            l++;
        else
        {
            if(lmax==l)
            {
                for(int j=i-l;j<i;j++)
                    cout<<z[j];
                cout<<'\n';
            }
            l=1;
        }
    }
    if(lmax==l)
    {
        for(int j=v.size()-l;j<v.size();j++)
            cout<<z[j];
        cout<<'\n';
    }
    exit(0);
}