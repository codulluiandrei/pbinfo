#include <iostream>
using namespace std;

int main()
{
    int n,p=0;
    cin>>n;
    cout<<(n+1)/2<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            {
                int dmin=100;
                if(i-1<dmin) dmin=i-1;
                if(n-i<dmin) dmin=n-i;
                if(j-1<dmin) dmin=j-1;
                if(n-j<dmin) dmin=n-j;
                cout<<dmin+1;
            }
        cout<<endl;
    }
    for(int i=0;i<(n+1)/2;i++)
        p=p+(i+1)*(n-2*i)*(n-2*i);
    cout<<p;
    return 0;
}
