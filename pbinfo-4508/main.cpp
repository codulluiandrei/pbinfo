#include <bits/stdc++.h>
using namespace std;
long long d;
int n,r,i,j,z;
int a[100003],b[100003],v[1000020],c[1000020];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> r;
    for(i = 1; i <= n; i++)
        cin >> a[i];
    for(i = 1; i <= n; i++)
    {
        cin >> b[i];
        if(b[i]>r){z++; v[b[i]]++;}
    }
    for(i = 1; i <= 1000000; i++)
    {
        j = i;
        while(j+r <= 1000000)
        {
            c[j+r] += v[i];
            j = j+i;
        }
    }
    for(i = 1; i <= n; i++)
    {
        d += c[a[i]];
        if(a[i]==r) d += z;
    }
    cout << d;
    return 0;
}