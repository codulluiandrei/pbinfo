//0 secunde
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    string s,ss;
    cin>>s>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x%2)
        {
            ss=s.substr(0,x);
            reverse(ss.begin(),ss.end());
            s+=ss;
        }
        else
        {
            ss=s.substr(0,x);
            s+=ss;
        }
    }
    cout<<s;
}