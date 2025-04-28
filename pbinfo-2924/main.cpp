#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
    cin>>n;
    if(n==1)
    {
        cout<<1;
        exit(0);
    }
	double sum=0;
	for(int i=2;i<=n;i++)
		sum+=(double)log(i)/(double)log(10);
	sum*=(double)n;
	cout<<fixed<<setprecision(0)<<ceil(sum);
	return 0;
}