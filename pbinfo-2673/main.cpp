#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    istringstream buffer(s);
    vector<string> v;
    for(string word; buffer>>word;)
    {
        s=word;
        for(int i=0; i<s.length(); i++)
            if(isalpha(s[i])==0)
                s.erase(s.begin()+i),i--;
        if(s!="")
            v.push_back(s);
    }
    for(int i=0,j=v.size()-1; i<j; i++,j--)
        cout<<v[i]<<'\n'<<v[j]<<'\n';
    if(v.size()%2)
        cout<<v[v.size()/2];
}