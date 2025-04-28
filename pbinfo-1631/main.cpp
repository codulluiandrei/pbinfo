#include <iostream>
#include <string.h>
using namespace std;
char s[256],a[30][11];
int main()
{
    unsigned i,nr=0,k=0,mx=0;
    cin.getline(s,256);
    char *p=strtok(s," ");
    while(p)
    {
        if(strlen(p)==3)
            nr++;
        if(strchr("aeiouAEIOU",p[0])&&strchr("aeiouAEIOU",p[strlen(p)-1]))
            strcpy(a[k++],p);
        if(strlen(p)>mx)
            mx=strlen(p);
        p=strtok(0," ");
    }
    cout<<nr<<'\n';
    for(i=0;i<k;i++)
        cout<<a[i]<<'\n';
    cout<<mx<<'\n';
    return 0;
}