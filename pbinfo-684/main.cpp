#include<cstdio>
#include<vector>
#define Nr vector<int>
using namespace std;
Nr X[1001];
int n,k,i,c,cnt[11],S[1001];
Nr operator+(Nr,Nr);
void read(),solve(),afiseaza(Nr);
int main()
{
	read();
	solve();
	return 0;
}
void read()
{
	freopen("cifre5.in","r",stdin);
	freopen("cifre5.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c);
		cnt[c]++;
	}
}
void solve()
{
	for(i=1,c=1;i<=k;)
	{
		if(!cnt[c]){c++;continue;}
		S[i]=c;cnt[c]--;n--;i++;
	}
	for(c=9,i=1;n;)
	{
		if(!cnt[c]){c--;continue;}
		X[i].push_back(c);cnt[c]--;n--;i++;if(i>k)i=1;
	}
	for(i=1;i<=k;i++)X[i].push_back(S[i]);
	//for(i=1;i<=k;i++)
	//	afiseaza(X[i]);
	for(i=k;i>1;i--)
		X[i-1]=X[i]+X[i-1];
	afiseaza(X[1]);
}
Nr operator+(Nr U,Nr V)
{
	Nr R;R.resize(0);
	int r=0;
	Nr::iterator iu,iv,ir;
	for(iu=U.begin(),iv=V.begin();iu!=U.end()&&iv!=V.end();iu++,iv++)R.push_back(*iu+*iv);
	for(;iu!=U.end();iu++)R.push_back(*iu);
	for(;iv!=V.end();iv++)R.push_back(*iv);
	for(ir=R.begin();ir!=R.end();ir++)
	{
		*ir+=r;r=0;
		if(*ir>9){*ir-=10;r=1;}
	}
	if(r)R.push_back(1);
	return R;
}
void afiseaza(Nr U)
{
	Nr::reverse_iterator iu;
	for(iu=U.rbegin();iu!=U.rend();iu++)
		printf("%d",*iu);
	printf("\n");
}