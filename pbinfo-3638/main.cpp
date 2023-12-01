#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
 
// #define fisier 1
 
using namespace std;
 
typedef long long ll;
 
const int mod = 1000000007;
const double eps = 1e-9;
 
string s;
int n, L;

int nxt[100002][27];

int frq[32];
ll cost;

int ans;
int main()
{
	#ifdef fisier
		ifstream cin("input.in");
		ofstream cout("output.out");
	#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> s;
	L = s.size();
	s = ' ' + s;
	for(char lit = 'a'; lit <= 'z'; ++lit)
	{
		nxt[L+1][lit - 'a'] = L+1;
		for(int i = L; i >= 1; --i)
		{
			if(s[i] == lit)
				nxt[i][lit - 'a'] = i;
			else
				nxt[i][lit - 'a'] = nxt[i+1][lit - 'a'];
		}
	}
	cin >> n;
	for(char lit = 'a'; lit <= 'z'; ++lit)
	{
		memset(frq, 0, sizeof(frq));
		cost = 0;
		int Rp = 1;
		int str = 0;
		for(int i = 1; i <= L; ++i)
		{
			str = min(str, Rp - i);
			while(Rp <= L && cost <= n)
			{
				if(s[Rp] == lit)
				{
					str = 0;
				}
				else
				{
					++str;
					frq[str]++;
					if(str == 1) 
						cost += 1;
					cost += (1LL<<(str-1));
				}
				++Rp;
				if(cost <= n)
					ans = max(ans, Rp - i);
			}
			if(s[i] != lit)
			{
				int nxtp = min(Rp - i, nxt[i][lit - 'a'] - i);
				cost -= (1LL<<(nxtp-1));
                if (nxtp == 1) 
					cost--;
				frq[nxtp]--;
			}
			if(cost <= n)
				ans = max(ans, Rp - i - 1);
		}
	}
	cout << ans;
	return 0;
}
