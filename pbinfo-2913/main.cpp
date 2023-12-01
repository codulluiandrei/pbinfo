#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k=1,x;
    cin>>n;
    n--;
    while(k<(n/k))
    {
        if(n%k==0)
        {
            x=n/k;
            if((x && !(x & (x - 1))))
            {
                cout<<"DA";
                return 0;
            }
        }
        k+=2;
    }
    cout<<"NU";
}
