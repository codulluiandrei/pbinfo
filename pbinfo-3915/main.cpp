#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
int n,X[13],P[13];
char s[13];
void afisare()
{
    for(int i=1;i<=n;i++)
        cout<<s[X[i]-1];
    cout<<"\n";
}
int valid(int k)
{
    if(k>1) ///daca sunt cel putin la cea de-a doua litera
    {
        if(strchr("aeiou",s[X[k]-1])==0 &&
           strchr("aeiou",s[X[k-1]-1])==0)
            return 0; ///doua consoane alaturare => 0
        if(strchr("aeiou",s[X[k]-1])!=0 &&
           strchr("aeiou",s[X[k-1]-1])!=0)
            return 0; ///doua vocale alaturate => 0
    }
    return 1;
}
void back(int k)
{
    for(int i=1;i<=n;i++)
        if(!P[i])
        {
            P[i]=1;
            X[k]=i;
            if(valid(k))
                if(k==n) afisare();
                else back(k+1);
            P[i]=0;
        }
}
void ordonare(char s[])
{
    int l=strlen(s);
    for(int i=0;i<l;i++)
        for(int j=i+1;j<l;j++)
            if(s[i]>s[j])
            {
                char aux=s[i];
                s[i]=s[j];
                s[j]=aux;
            }
}
int main()
{
    cin>>s;
    n=strlen(s);
    int cv=0,cc=0;
    for(int i=0;i<n;i++)
        if(strchr("aeiou",s[i])==0) cc++;///numaram consoanele
        else cv++;///numaram vocalele
    if(abs(cc-cv)>1) cout<<"IMPOSIBIL";///diferenta>1 => imposibil
    else
    {
        ordonare(s);///ordonez alfabetic cuvantul
        back(1);
    }
    return 0;
}