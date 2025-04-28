#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,ss;
    getline(cin,s);
    vector<string> v;
    istringstream buffer(s);
    for(string word;buffer>>word;)
        v.push_back(word);
    for(int i=0;i<v.size()-1;i++)
        for(int j=i+1;j<v.size();j++)
        {
            s=v[i],ss=v[j];
            if(s.size()<ss.size())
                swap(v[i],v[j]);
            else
            if(s.size()==ss.size())
                if(s>ss)
                    swap(v[i],v[j]);
        }
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<'\n';
}