#include <iostream>
#include <cstring>
using namespace std;
int palindrom(char s[])
{
    for(int i=0,j=strlen(s)-1;i<j;i++,j--)
        if(s[i]!=s[j]) return 0;
    return 1;
}
int main()
{
    char s[101],pmax[101]="",smax[101]="",suf[101],pre[101];
    cin>>s;
    for(int i=0;i<=strlen(s);i++)
    {
        strcpy(suf,s+i);
        strcpy(pre,"");
        strncat(pre,s,i);
        if(palindrom(pre)) strcpy(pmax,pre);
        if(palindrom(suf) && strlen(suf)>strlen(smax)) strcpy(smax,suf);
    }
    cout<<pmax<<" "<<smax;
    return 0;
}