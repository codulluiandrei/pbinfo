#include <iostream>
using namespace std;
int v[100001];
int main()
{
    int i=0,j=0,maxs=0,nr=0,n,k;
    cin>>n>>k;
    for(i=0; i<n; i++)
        cin>>v[i];
    for(i=0; i<n; i++)
    {
        if(v[i]==0) nr++;
        if(nr<=k)
        {
            if(maxs<i-j+1)
                maxs=i-j+1;
        }
        else
            while(nr>k)
            {
                if(v[j]==0) nr--;
                j++;
            }
    }
    cout<< maxs;
    return 0;
}