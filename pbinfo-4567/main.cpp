#include <iostream>
using namespace std;
int main()
{
    int n,x,c=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        int nc=0,y=x,p=1,a,b,r;
        while(y>0)    ///calculez numarul de cifre ale lui x
        {
            nc++;
            y=y/10;
        }
        for(int i=1;i<=nc/2;i++)
            p=p*10;   ///calculez 10 la nc/2
        if(nc%2==0)  ///numar par de cifre
        {
            a=x/p;   ///cele 2 jumatati
            b=x%p;
            r=b*p+a; ///interchimbarea lor
        }
        else ///numar impar de cifre
        {
            a=x/p/10;   ///cele 2 jumatati
            b=x%p;
            r=(b*10+x/p%10)*p+a; ///interchimbarea lor cu atentie la cifra din mijloc
        }
        if(r==x) c++;   ///daca e rotund
    }
    cout<<c;
    return 0;
}