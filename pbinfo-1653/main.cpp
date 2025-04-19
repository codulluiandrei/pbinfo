#include <iostream>
#include <algorithm>
using namespace std;
int v[105],v1[105],n;
int main()
{
    int i,da=1,j;
    cin >> n;
    for(i=0;i<n;i++)
        cin >> v[i];
    for(i=0;i<n;i++)
        cin >> v1[i];
    for(i=0;i<n;i++)
        for(j=i+1;j<=n;j++)
            if(v[j]>v[i])
                swap(v[i],v[j]);
    for(i=0;i<n;i++)
        for(j=i+1;j<=n;j++)
            if(v1[j]>v1[i])
                swap(v1[i], v1[j]);
    for(i=1;i<n;i++)
        if(v[i-1]*v1[n-i]!= v[i]*v1[n-i-1]) // i.p
            da=0;
    if(da)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}