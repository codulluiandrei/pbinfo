#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[255],sep[]=".,!?";
    int n;
    cin>>n;
    cin.get();
    for(int i=1;i<=n;i++)
    {
        cin.getline(s,sizeof(s));
        for(int j=0;j<strlen(s);j++)
        if(strchr(sep,s[j]) && s[j+1]!=NULL)
        {
            char aux[255];
            strcpy(aux,s+j+1);
            strcpy(s+j,aux);
            j--;
        }
        cout<<s<<'\n';
    }
    return 0;
}