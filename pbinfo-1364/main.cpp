#include <fstream>
using namespace std;
ifstream f("produs3.in");
ofstream g("produs3.out");
long long n,i,j,k,i1,j1,k1,d[22],t[16],c[12],p,e2[1000002],e3[1000002],e5[1000002],exp2,exp3,exp5;
long long cod,sol,viz[10],x;
int main()
{
    f >> n ;
    // calculez puterile lui 2,3 si 5 mai mici decat 1000000
    d[0]=1;
    i=0;
    while(d[i]<1000000){i++; d[i]=d[i-1]*2;}
    i--;
    t[0]=1;
    j=0;
    while(t[j]<1000000){j++; t[j]=t[j-1]*3;}
    j--;
    c[0]=1;
    k=0;
    while(c[k]<1000000){k++; c[k]=c[k-1]*5;}
    k--;
    // calculez numerele mai mici decat 1000000 ce sunt divizibile doar cu 2, 3 sau 5
    for(i1=0;i1<=i;i1++)
      for(j1=0;j1<=j;j1++)
        for(k1=0;k1<=k;k1++)
           {
               p=d[i1]*t[j1]*c[k1];
               if(p<1000000)
                {
                    e2[p]=i1;
                    e3[p]=j1;
                    e5[p]=k1;
                }
           }
     // citesc numerele si formez exponentii cumulati ai lui 2, 3 si 5
     exp2=0;exp3=0;exp5=0;
     viz[0]=1;
     for( i=1 ; i<=n ; i++)
     {
         f >> x ;
         exp2=exp2+e2[x];
         exp3=exp3+e3[x];
         exp5=exp5+e5[x];
         cod=(exp2%2)*4+(exp3%2)*2+exp5%2;
         viz[cod]++;
     }
     // Numar perechile de coduri de acelasi tip care se pot forma, intre acestea fiind o secventa
     // cu proprietatea ceruta
     sol=0;
     for( i=0 ; i<=7 ; i++)
       sol=sol+viz[i]*(viz[i]-1)/2;
     g << sol ;
    return 0;
}