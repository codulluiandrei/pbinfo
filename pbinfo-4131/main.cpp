#include <bits/stdc++.h>
using namespace std;
ifstream in("joc.in");
ofstream out("joc.out");
int c,n,apoz,bpoz,i,mutare,vap[12001],vbp[12001],nra,nrb, cif[7]= {0}, maxx=0,a,b,X ;
int main()
{
    in>>c>>n;
    /// calculez numarul de divizori ai lui n

    int d=2,p=1,nr=0,x=n;
    while(x>1)
    {
        nr=0;
        while(x%d==0)
            nr++,x/=d;
        p*=(nr+1);
        d++;
        if(d*d>x and x>1) x=1,p*=2;
    }
    if(c==1)
        out<<p;
    else
    {
        a=1;
        b=0;
        apoz=1,bpoz=1;  /// pun pionii pe prima pozitie
        vap[1]=vbp[1]=nra=nrb=1; /// pun in vectori pozitiile pionilor
        while(apoz<n && bpoz<n)
        {
            mutare++; /// de cate ori il calculeaza pe X copii
            if(mutare%2==1)
                X=(mutare+(a*apoz+b*bpoz+n)%10)%6+1;
            else
                X=((mutare+1)%5+(a*apoz+b*bpoz+n)%10)%6+1;

            cif[X]++;
            if(maxx<cif[X]) maxx=cif[X];
            apoz+=a*X;  /// daca a=1 si b=0
            bpoz+=b*X;  /// daca a=0 si b=1
            if(a==1)
            {

                if(apoz<=n)/// sunt in tabla
                    vap[++nra]=apoz;
                else vap[++nra]=n,apoz=n;  /// am iesit din tabla
                if(apoz==bpoz)bpoz=1,vbp[++nrb]=1;  /// sa nu uit sa trec pozitia de intoarcere in vector
            }

            else
            {
                if(bpoz<=n)
                    vbp[++nrb]=bpoz;
                else vbp[++nrb]=n,bpoz=n;
                if(apoz==bpoz)apoz=1,vap[++nra]=1; /// sa nu uit sa trec pozitia de intnrarcere in vector
            }

         if(X==6)
           a%=2,b%=2;/// ramane ordinea mutarii copiilor
         else
                a=(a+1)%2,b=(b+1)%2;/// schimb ordinea mutarii copiilor
        }
        if(c==2)
            out<<maxx;
        else
        {
            if(apoz==n)
                for(i=1; i<=nra; i++)
                    out<<vap[i]<<" ";
            else for(i=1; i<=nrb; i++)
                    out<<vbp[i]<<" ";
        }

    }
}
