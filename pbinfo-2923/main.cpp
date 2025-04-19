#include<bits/stdc++.h>
using namespace std;
int v[1000000],n,ans;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
        cin>>v[i];
	for (int i=0,j=n-1; i<=j;)
	{
		if (v[i] == v[j])
		{
			i++;
			j--;
		}
		else if (v[i] > v[j])
		{
			j--;
			v[j] += v[j+1] ;
			ans++;
		}
		else
		{
			i++;
			v[i] += v[i-1];
			ans++;
		}
    }
    cout<<ans;
	return 0;
}