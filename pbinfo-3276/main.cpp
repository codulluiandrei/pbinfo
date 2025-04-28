#include<bits/stdc++.h>
using namespace std;
int a[1001], n;
float c[1001];
float Min2(float x, float y)
{
    return (x < y ? x : y);
}
float Min3(float x, float y, float z)
{
    return Min2(Min2(x,y), z);
}
int main()
{
    int i;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    /// dp
    c[0] = 0;
    c[1] = a[1];
    c[2] = a[1] + a[2] - Min2(a[1],a[2])/2;
    for (i = 3; i <= n; i++)
        c[i] = Min3(c[i-3]+a[i-2]+a[i-1]+a[i]-Min3(a[i-2],a[i-1],a[i]),
		c[i-2]+a[i-1]+a[i]-Min2(a[i-1],a[i])/2, c[i-1] + a[i]);
    cout << setprecision(1) << fixed << c[n];
    return 0 ;
}