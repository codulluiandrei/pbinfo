#include <iostream>
using namespace std;
int main()
{
    int A[201],n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>A[i];
    for(int i=1;i<=n;i++)
    {
        int F[10]={0};
        int x=A[i];
        while(x>0)
        {
            F[x%10]++;
            x=x/10;
        }
        for(int i=9;i>=0;i--)
            for(int j=1;j<=F[i];j++)
                x=x*10+i;
        A[i]=x;
    }
    for(int i=n;i>=1;i--)
        cout<<A[i]<<" ";
    return 0;
}