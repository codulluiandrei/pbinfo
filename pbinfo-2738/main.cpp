#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ok=0;
    string s,ss;
    getline(cin,s);
    vector<string> v;
    istringstream b(s);
    for(string w;b>>w;)
        v.push_back(w);
    for(int i=0;i<v.size();i++)
    {
        ok=0;
        vector<int> w(300);
        s=v[i];
        for(int j=0;j<s.size();j++)
            if(!w[s[j]])
                w[s[j]]++,ok=1;
            else
            {
                ok=0;
                break;
            }
        if(ok && s.size()>ss.size())
            ss=s;
    }
    if(ss=="")
        cout<<-1;
    else
        cout<<ss;
}