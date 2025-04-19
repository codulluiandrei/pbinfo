#include <fstream>
#include <iostream>
using namespace std;
long long H,h_max,maxi_pare;
long long C,latura1,latura2,n,i,l;
int main()
{
    cin>>C>>n;
    if (C==1)
    {
        l=0;
        for(i=1; i<=n; i++)
        {
            cin>>latura1;
            l=0;
            while(latura1%2==0 && i<=n)
            {
                l++;
                cin>>latura1;
                i++;
            }
            if (l>maxi_pare)
                maxi_pare=l;
        }
        cout<<maxi_pare<<'\n';
    }
    if(C==2)
    {
        cin>>latura1;
        h_max=H=latura1;
        for(i=1; i<=n-1; i++)
        {
            cin>>latura2;
            if(latura2<latura1)
            {
                H=H+latura2;
            }
            else
                H=latura2;
            if(H>h_max)
                h_max=H;
            latura1=latura2;
        }
        cout<<h_max<<'\n';
    }
    return 0;
}