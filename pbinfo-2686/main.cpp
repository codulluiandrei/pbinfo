#include<bits/stdc++.h>
using namespace std;
vector<int> z(64000);
int main()
{
    vector<int> w;
    int sum=0,ok=0,okk=0;
    string s;
    getline(cin,s);
    istringstream buffer(s);
    vector<string> v;
    for(string word;buffer>>word;)
        v.push_back(word);
    for(int i=0;i<v.size();i++)
    {
        s=v[i],sum=0,ok=0;
        for(int j=0;j<s.size();j++)
        {
            if(isalpha(s[j]))
                ok=1;
            sum+=s[j];
        }
        if(ok==1 && z[sum]==0)
        w.push_back(sum),z[sum]++,okk=1;
        else
        if(ok==0)
        v.erase(v.begin()+i),i--;
    }
    if(okk==0)
    {
        cout<<"NU EXISTA";
        return 0;
    }
    sort(w.begin(),w.end());
    for(int i=0;i<w.size();i++)
    {
        cout<<w[i]<<" ";
        for(int j=0;j<v.size();j++)
        {
            s=v[j],sum=0;
            for(int k=0;k<s.size();k++)
                sum+=s[k];
            if(sum==w[i])
                cout<<s<<" ";
        }
        cout<<'\n';
    }
}