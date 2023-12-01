#include <stdio.h>

FILE *f,*g;


int poz[100010];
long long n,i,j,k,sum,vi;

int main()
{   f=fopen("roata.in","r");
    g=fopen("roata.out","w");
    fscanf(f,"%lld",&n);
    for (i=0;i<n;i++)
    {

        fscanf(f,"%lld",&j);
        poz[j-1]=i;
    }
    k=0;j=0;sum=0;vi=0;
    for (i=0;i<n;i++)
    {
        k=n-(sum+poz[i])%n;
        if(k<=j){vi+=n;}
        j=k;
        k=k+vi;
        sum+=k;
        fprintf(g,"%lld ",k);

    }
    return 0;
}
