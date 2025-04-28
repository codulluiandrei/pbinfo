//autor Adrian Airinei 
//O(YMAX*N)-100 puncte
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 50100
#define MAX_Y 1010
#define MOD 946021
#define PI pair<int, int>
int N, res;
vector< PI > Y[MAX_Y];
void read_data(void)
{
	int i, a, b, y;
	scanf("%d", &N);
	for(i = 1; i <= N; i++)
		scanf("%d %d %d", &y, &a, &b), Y[y].push_back(make_pair(a,b));
}
void normalize(void)
{
	int i, j, k, cnt;
	for(i = 0; i < MAX_Y; i++)
	{
		sort(Y[i].begin(), Y[i].end());
		cnt = 0;
		for(j = 0; j < Y[i].size(); j++)
		{
			k = j;
			while(j+1 < Y[i].size() && Y[i][j+1].first >= Y[i][k].first && Y[i][j+1].first <= Y[i][k].second)
				Y[i][k].second = max(Y[i][k].second, Y[i][j+1].second), j++;
			Y[i][cnt++] = Y[i][k];
		}
		Y[i].resize(cnt);
	}
}
int intersect(PI a, PI b)
{
	if(a.first >= b.first && a.first <= b.second)
		return min(a.second, b.second)-a.first+1;
	if(b.first >= a.first && b.first <= a.second)
		return min(b.second, a.second)-b.first+1;
	return 0;
}
void solve(void)
{
	int i, j, k, indi, indj, r;
	for(i = 0; i < MAX_Y; i++)
		for(j = i+1; j < MAX_Y; j++)
		{
			r = indi = indj = 0;
			while(indi < Y[i].size() && indj < Y[j].size())
			{
				r += intersect(Y[i][indi], Y[j][indj]);
				if(Y[i][indi].second <= Y[j][indj].second)
					indi++;
				else
					indj++;
			}
			res += (int) ( (long long)r*(r-1)/2%MOD );
			res %= MOD;
		}
}
int main(void)
{
	freopen("drept.in", "rt", stdin);
	freopen("drept.out", "wt", stdout);
	read_data();
	normalize();
	solve();
	printf("%d
", res);
	return 0;
}