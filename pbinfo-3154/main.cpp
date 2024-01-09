#include <iostream>
#include <cstring>
using namespace std;

int n,X[12],P[12];
char s[12],v[]="aeiou";

void afisare()
{
    for(int i=1;i<=n;i++)
       cout<<s[X[i]];
    cout<<'\n';
}

int ok(int k)
{
    if((s[X[k]]=='a' ||  s[X[k]]=='e' || s[X[k]]=='i' || s[X[k]]=='o' || s[X[k]]=='u') && X[k]!=k-1)
        return 0;
    return 1;
}

void back(int k)
{
    for(int i=0;i<n;i++)
        if(!P[i])
        {
            X[k]=i;
            P[i]=1;
            if(ok(k))
            {
                if(k==n)
                    afisare();
                else back(k+1);
            }
            P[i]=0;
        }
}

int main()
{
    cin>>s;
    n=strlen(s);
    for(int i=0;i<n;i++)
        if(strchr(v,s[i])==0)
            for(int j=i+1;j<n;j++)
                if(strchr(v,s[j])==0)
                    if(s[i]>s[j] )
                    {
                        char aux=s[i]; s[i]=s[j]; s[j]=aux;
                    }
    back(1);
    return 0;
}
