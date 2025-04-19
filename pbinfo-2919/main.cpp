#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<long long> group1,group2;
	long long n,s,group1s;
	cin>>n;
	s=n*(n+1)/2;
	group1s=s/2;
	for(long long i=n;i>0;i--)
    {
		if(group1s-i>= 0)
            group1.push_back(i),group1s-=i;
		else
			group2.push_back(i);
	}
	for(long long i=0;i<group1.size();i++)
        cout<<group1[i]<<" ";
    cout<<'\n';
    for(long long i=0;i<group2.size();i++)
        cout<<group2[i]<<" ";
}