#include<iostream>
#include<fstream>
using namespace std;
ifstream f("cifre10.in");
ofstream g("cifre10.out");
int a[10],b[10],n,i,x,y,j,k,p,cod,cate,maxim, minim;
int main()
{
    f>>p>>n;
    for(i=1;i<=n;i++)
    {
        f>>x>>y;
        for(j=0;j<10;j++) a[j]=b[j]=0;
        while(x) {a[x%10]++; x=x/10;}
        while(y) {b[y%10]++; y=y/10;}
        cod=0;
        for(j=9;j>=0;j--)
            if(a[j]>0 && b[j]>0)
            {
                if(a[j]<b[j]) minim=a[j]; else minim=b[j];
                for(k=1;k<=minim;k++) cod=cod*10+j;
            }
        if(cod) cate++;
        if(cod>maxim) maxim=cod;
    }
    if(p==1) g<<cate;
       else g<<maxim;
    g.close();
    return 0;
}
