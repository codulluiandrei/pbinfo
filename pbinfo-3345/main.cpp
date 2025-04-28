#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
ifstream fin("divimax.in");
ofstream fout("divimax.out");
struct numar{
    char sir[13];}a[3100];
int n,c;
int divi(int x)
{   int f=2,p=1;
    while(x>1)
    {
        if(x%f==0)
        {
            if(p<f)p=f;
            while(x%f==0)
                x=x/f;
        }
        if(f==2)f=3;
        else f++;
    }
    return p;
}
void conversie(int x, char s[])
{
    int k=0,i,j;
    while(x)
    {
        s[k++]=x%10+'0'; x=x/10;
    }
    s[k]='\0';
    i=0, j=k-1;
    while(i<j)
        { swap(s[i],s[j]); i++; j--; }
}
bool comp( numar x, numar y)
{
    char z[30],t[30];
    strcpy(z,x.sir);
    strcat(z,y.sir);
    strcpy(t,y.sir);
    strcat(t,x.sir);
    return strcmp(z,t)>0;
}
int main()
{
	fin>>c>>n;
	int i,x,p,maxp=0;
	for (i=1; i<=n; i++)
		{
		    fin>>x;
            p=divi(x);
            maxp=max(maxp,p);
            conversie(p,a[i].sir);
		}
    sort(a+1,a+n+1, comp);
    if(c==1)
        {fout<<maxp<<endl; return 0;}
    ///C=2
    for (i=1; i<=n; i++)
	   fout<<a[i].sir;
	return 0;
}