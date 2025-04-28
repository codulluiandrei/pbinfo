#include<bits/stdc++.h>
using namespace std;
ifstream in("lungimerandmax.in");
ofstream out("lungimerandmax.out");
string s;
vector<string> v;
int main()
{
    int l,lr=0;
    in>>l;
    in.get();
    getline(in,s);
    istringstream buffer(s);
    for(string word;buffer>>word;)
        v.push_back(word);
    for(int i=0;i<v.size();i++)
    {
        s=v[i];
        lr+=s.size()+1;
        if(lr<=l)
            out<<s<<" ";
        else
        {
            out<<'\n';
            out<<s<<" ";
            lr=s.size();
        }
    }
    out<<'\n';
}