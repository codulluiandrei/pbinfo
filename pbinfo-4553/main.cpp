#include <iostream>
using namespace std;
int main()
{
    int n;
    long long s=0;
    cin>>n;
    for(int k=1;k<=n;k++)
    {
        long long a,x;
        cin>>a;
        int nc=0; ///numarul de cifre ale lui a
        x=a;
        while(x>0)
        {
            nc++;
            x=x/10;
        }
        int alipit=0;
        for(int i=1;i<=nc/2;i++) ///impart in cel putin 2 numere cu i cifre
            if(nc%i==0) ///daca se poate imparti!
            {
                long long p=1; /// 10^i
                for(int j=1;j<=i;j++)
                    p=p*10;
                int gu=a%p,ok=1;///gu = grupul ultimelor i cifre
                x=a;
                while(x>0)
                {
                    if(x%p!=gu) ok=0;///nu e alipit cin grupuri de i cifre
                    x=x/p; ///despart in grupuri de cate i cifre
                }
                if(ok) alipit=1;
            }
        if(a>9 && alipit) s=s+a;
    }
    cout<<s;
    return 0;
}