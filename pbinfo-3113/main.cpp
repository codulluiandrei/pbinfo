#include<bits/stdc++.h>
using namespace std;

map<string,int> v;

int main()
{
    string s;
    getline(cin,s);
    istringstream b(s);
    for(string w;b>>w;)
    {
        while(ispunct(w.back()))
            w.pop_back();
        while(ispunct(w[0]))
            w.erase(w.begin()+0);
        v[w]++;
    }
    for(auto i:v)
        cout<<i.first<<" "<<i.second<<'\n';
}
