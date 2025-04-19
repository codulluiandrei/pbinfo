#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[256];
    int n,ok=0,t=0,ap=0,lmax=0;
    cin.getline(s,sizeof(s));
    n=strlen(s);
    while(s[t]!=' ')
        t++;
    for(int i=0; i<n; i++)
    {
        ok=0,ap=0;
        if(s[i]==' ' || i+1==n)
        {
            if(i+1==n)
                i++;
            for(int j=t; j<i; j++)
            {
                if(isalpha(s[j]))
                    ok=1;
                ap++;
            }
            if(ok==1)
                if(ap>lmax)
                    lmax=ap;
            if(n!=i)
            {
                t=i;
                while(s[t]==' ')
                    t++;
            }
        }
    }
        t=0;
        while(s[t]==' ')
        t++;
        for(int i=t; i<n; i++)
        {
            if(s[i]==' ' || i+1==n)
            {
                ok=0;
                if(i+1==n)
                    i++;
                for(int j=t; j<i; j++)
                    if(isalpha(s[j]))
                        ok=1;
                if(ok==1)
                    if(i-t==lmax)
                    {
                        for(int x=t,y=i-1; x<y; x++,y--)
                            swap(s[x],s[y]);
                    }
                if(n!=i)
                {
                    t=i;
                    while(s[t]==' ')
                        t++;
                }
            }
        }
        cout<<s;
        return 0;
}