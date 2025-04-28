#include <iostream>
using namespace std;
int main()
{
    int n,m,s=0,A[101];
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>A[i];
        s=s+A[i];
    }
    if(s<n) cout<<"imposibil";
    else
    {
        for(int i=1;i<m;i++)
            for(int j=i+1;j<=m;j++)
                if(A[i]<A[j])
                    swap(A[i],A[j]);
        int i=1;
        while(n>0)
            if(n-A[i]>0)
            {
                n=n-A[i];
                i++;
            }
            else n=0;
        cout<<i;
    }
    return 0;
}