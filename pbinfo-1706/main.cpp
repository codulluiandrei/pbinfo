#include <fstream>
using namespace std;
ifstream  fin("stele.in");
ofstream fout("stele.out");
long long v[26];
long long nr[26];
void cerinta1(int nr, char s[])
{
    char x;
    int i=0, j=0;
    while(i<25 && v[i]<=nr)i++;
    while(nr>0)
    {
        while(v[i]>nr)i--;
        s[j++]=i+'a';
        nr-=v[i];
    }
    s[j]=0;
    i=0;j--;
    while(i<j)
        x=s[i],s[i]=s[j],s[j]=x,i++,j--;
}
void numarare(char s[])
{
    int i=0;
    long long n=0;
    if(s[0]>='a' && s[0]<'z')
        nr[s[i]-'a']+=1, i=1;
    for(;s[i];i++)
        if(s[i]>='0' && s[i]<='9')
            n=n*10+s[i]-'0';
        else
            if(s[i-1]>='a' && s[i-1]<='z')
                nr[s[i]-'a']+=1;
            else
                nr[s[i]-'a']+=n, n=0;
}
void prod(long long nr, long long v, int rez[])
{
    int i;
    long long t=0;
    rez[0]=0;
    while(nr)
        rez[++rez[0]]=nr%10, nr/=10;
    for(i=1; i<=rez[0] || t; i++)
        t+=rez[i]*v, rez[i]=t%10, t/=10;
    rez[0]=i-1;
}
void add(int s[], int rez[])
{
    int i;
    long long t=0;
    for(i=1;i<=s[0] || i<=rez[0] || t; i++, t/=10)
        t+=s[i]+rez[i], s[i]=t%10;
    s[0]=i-1;
}
void suma()
{
    int s[101]={0}, rez[101], i, j;
    s[0]=1;
    s[1]=0;
    for(i=0;i<26;i++)
        if(nr[i])
        {
            for(j=0;j<100;j++)rez[j]=0;
            prod(nr[i], v[i], rez);
            add(s, rez);
        }
    for(i=s[0];i>=1;i--)
        fout<<s[i];
    fout<<'\n';
}
int main()
{
    int n, C, i, p=1;
    char s[500];
    for(i=0;i<26;i++)
        v[i]=p,p*=2;
    fin>>C>>n;
    if(C==1)
        cerinta1(n, s), fout<<s<<'\n';
    else
    {
        for(i=1;i<=n;i++)
            fin>>s, numarare(s);
        suma();
    }
	fin.close();
	fout.close();
    return 0;
}