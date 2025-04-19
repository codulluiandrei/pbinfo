// solutie 100 pct Mihai Georgescu
#include <iostream>
#include <bitset>
using namespace std;
bitset<500000> c;
int n,x,nr;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        c[x]=1;
    }
    for(int i=1; i<=200000; i++)
    {
        for(int j=2*i; j<=400000; j=j+i)
        {
            if(j%2==0)
            {
                if(c[j/2]==1)
                {
                    if(c[j/2-i]==1)
                        nr++;
                }
            }
        }
    }
    cout<<nr;
    return 0;
}