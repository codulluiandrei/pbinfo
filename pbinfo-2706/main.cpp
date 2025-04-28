#include <bits/stdc++.h>
using namespace std;
const int MAX=100;
int G[MAX][MAX],n,k,i,j,S[MAX],maxk=0;
int ok(int i)
{
	if(i>1&&S[i-1]>=S[i])
		return 0;
	for(j=1;j<i;j++)
		if(G[S[i]][S[j]]==0)
			return 0;
	return 1;
}
int main()
{
	ifstream fin("serbare2.in");
	ofstream fout("serbare2.out");
	fin>>n>>k;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			fin>>G[i][j];
	i=1;
	S[i]=0;
	while(i>0)
		if(S[i]<n)
		{
			S[i]++;
			if(ok(i))
            {
				if(k==i)
				{
					maxk=i;
					break;
				}
				else
				{
					maxk=maxk<i?i:maxk;
					S[++i]=0;
				}
            }
		}
		else i--;
	fout << maxk << "\n";
	fin.close();
	fout.close();
	return 0;
}