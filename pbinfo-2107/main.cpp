#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("pomi.in");
ofstream fout("pomi.out");
char x[81];
short a[100],b[100],k;
short c[100],d[100],e[100];
void setare(short *a, char *x)
{
    int i,lg;
    lg=a[0]=strlen(x);
    for(i=0; i<lg; ++i)
        a[lg-i]=x[i]-'0';
}
void divide(const short *a, short k,short *d)
{
    short lg1,nr,i,lg2,j;
    lg1=a[0];
    if(a[lg1]<k)
    {
        nr=a[lg1];
        i=lg1-1;
        lg2=lg1-1;
    }
    else
        i=lg2=lg1,nr=0;
    for(j=lg2; j>=1; --j,--i)
    {
        nr=nr*10+a[i];
        d[j]=nr/k;
        nr=nr%k;
    }
    d[0]=lg2;
}
void scade1(short *a)
{
    short i;
    i=1;
    while(a[i]==0)
    {
        a[i]=9;
        i++;
    }
    a[i]--;
    if(a[i]==0 && i==a[0])
        a[0]--;
}
void diferenta(short *a, short *b, short *e)
{
    short i,T=0;
    e[0]=max(a[0],b[0]);
    for(i=1; i<=c[0]; ++i)
    {
        e[i]=a[i]-b[i]+T;
        if(e[i]<0)
        {
            e[i]+=10;
            T=-1;
        }
        else
            T=0;
    }
    while(!e[e[0]] && e[0]>1)
        e[0]--;
}
int main()
{
    fin>>x;
    setare(a,x);
    fin>>x;
    setare(b,x);
    fin>>k;
    divide(b,k,c);
    scade1(a);
    divide(a,k,d);
    diferenta(c,d,e);
    for(short i=e[0]; i>=1; --i)
    fout<<e[i];
    fout<<'\n';
    return 0;
}