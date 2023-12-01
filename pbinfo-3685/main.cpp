#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
 
// #define fisier 1
 
using namespace std;
 
typedef long long ll;
 
const int mod = 1000000007;
const double dancila = 3.14159265359; // PI 
const double eps = 1e-9;
 
int n, v[100002];
int x, p;
int d[12];

bool prim[1000002];
int prod[1000002];
int sc[1000002];
int price[1000002];

void precompute()
{
	prim[0] = 1, prim[1] = 1; 
	
	for(int i = 2; i <= 1000000; ++i) 
		if(!prim[i])
			for(int j = i+i; j <= 1000000; j += i)
				prim[j] = 1;
	
	for(int i = 1; i <= 1000000; ++i)
	{
		int nr = i;
		int pc = 1;
		int sc = 0;
		
		price[i] += x; 
		
		if(!prim[i]) 
			price[i] = price[i] + p + i;
		while(nr)
		{
			int dg = nr%10;
			if(!prim[dg]) 
				price[i] += d[dg];
			pc *= dg;
			sc += dg;
			nr /= 10;
		}
		
		if(!prim[sc]) 
			price[i] += sc;
			
		if(!prim[pc]) 
			price[i] += pc;	
	}
}


 
int main()
{
	#ifdef fisier
		ifstream cin("input.in");
		ofstream cout("output.out");
	#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	cin >> n;
	
	for(int i = 1; i <= n; ++i)
		cin >> v[i];
	
	cin >> x >> p;
	
	cin >> d[2] >> d[3] >> d[5] >> d[7];
	
	precompute();
	
	
	ll ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		deque<int> d;
		int nr = v[i];
		int val = price[v[i]];
		int wh = v[i];
		while(nr)
		{
			d.push_front(nr%10);
			nr /= 10;
		}
		int coef = 1;
		for(int poz = d.size() - 1; poz >= 0; --poz)
		{
			int nr = v[i] - d[poz] * coef + (poz == 0) * coef;
			for(int nd = 0 + (poz == 0); nd <= 9; ++nd)
			{
				if(price[nr] > val)
					val = price[nr], wh = nr;
				nr += coef;
			}
			coef *= 10;
		}
		ans += val;
	}
	cout << ans;
	return 0;
}
