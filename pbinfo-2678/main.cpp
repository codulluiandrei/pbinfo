#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[256];
    int n,i,nr=0,sum=0;
    cin.getline(s,256);
    n=strlen(s);
    for(i=0;i<n;i++)
        if(s[i]>='0'&&s[i]<='9')
    nr=nr*10+(s[i]-'0');
    else
    {
        sum=sum+nr;
        nr=0;
    }
    cout<<sum;
    return 0;
}
