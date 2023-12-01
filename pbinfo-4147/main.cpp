#include <iostream>
using namespace std;

int main()
{
    int F[11]={0},n;
    long long c=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        {
            int x,nc=0;
            cin>>x;
            if(x==0) nc=1;
            while(x>0)
            {
                nc++;
                x=x/10;
            }
            F[nc]++;
        }
    for(int i=1;i<=10;i++)
        c=c+1LL*F[i]*(F[i]-1)/2;
    cout<<c;
    return 0;
}
