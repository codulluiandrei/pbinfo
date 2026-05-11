#include <bits/stdc++.h>
using namespace std;
ifstream f("valoare.in");
ofstream g("valoare.out");
int C;
char s[1010];
int main()
{
    f>>C>>s;
    if(C==1)
    {
        int i, cate=0;
        bool ap[26]= {};
        for(i=0; s[i]; i++)
            if(s[i]>='A' && s[i]<='Z')
                ap[s[i]-'A']=1;
        for(i=0; i<26; i++)
            if(ap[i])cate++;
        g<<cate<<'\n';
    }
    else if (C==2)
    {
        long long S=0, nr=0;
        int i;
        for(i=0; s[i];)
            if(s[i]>='0' && s[i]<='9')
            {
                while(s[i]>='0' && s[i]<='9')
                    nr=nr*10+(s[i]-'0'), i++;
                S+=nr;
                nr=0;
            }
            else i++;
            g<<S<<'\n';
    }
    else
    {
        long long v[1010]= {-1}, S, nr;
        int i, k=0;
        for(i=0; s[i]; i++)
            if(s[i]=='(')v[++k]=-1;
            else if(s[i]>='A' && s[i]<='Z')
                    v[++k]=s[i]-'A'+1;
                else if(s[i]==')')
                {
                    S=0;
                    while(k>0 && v[k]!=-1)
                        S+=v[k], k--;
                    v[k]=S;
                }
                else if(s[i]>='0' && s[i]<='9')
                {
                    nr=s[i]-'0';
                    while(s[i+1]>='0' && s[i+1]<='9')nr=nr*10+(s[i+1]-'0'), i++;
                    v[k]*=nr;
                }
        S=0;
        while(k>0)S+=v[k], k--;
        g<<S<<'\n';
    }
    return 0;
}