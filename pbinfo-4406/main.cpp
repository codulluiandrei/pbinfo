/// Lect. univ. Csaba Gyorgy Patcas¸ - Universitatea Babes-Bolyai, Cluj-Napoca
#include <vector>
#include <string> 
#include <set> 
#include <map> 
#include <unordered_set>
#include <unordered_map>
#include <queue> 
#include <bitset> 
#include <stack>
#include <list>
#include <numeric> 
#include <algorithm> 
#include <random>
#include <chrono>
#include <cstdio>
#include <fstream>
#include <iostream> 
#include <sstream> 
#include <iomanip>
#include <cctype>
#include <cmath> 
#include <ctime>
#include <cassert>
using namespace std;
#define LL long long
#define PII pair <int, int>
#define VB vector <bool>
#define VI vector <int>
#define VLL vector <LL>
#define VD vector <double>
#define VS vector <string>
#define VPII vector <pair <int, int> >
#define VVI vector < VI >
#define VVB vector < VB >
#define SI set < int >
#define USI unordered_set <int>
#define MII map <int, int>
#define UMII unordered_map <int, int>
#define MS multiset
#define US unordered_set
#define UM unordered_map
#define UMS unordered_multiset
#define UMM unordered_multimap
#define FORN(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define SZ size()
#define BG begin() 
#define EN end() 
#define CL clear()
#define X first
#define Y second
#define RS resize
#define PB push_back
#define MP make_pair
#define ALL(x) x.begin(), x.end()
#define INS insert
#define ER erase
#define CNT count
#define IN_FILE "fibosnek.in"
#define OUT_FILE "fibosnek.out"
template <typename T>
void PR(T var1)
{
	cout << var1 <<endl;
}
template <typename T, typename... Types>
void PR(T var1, Types... var2)
{
	cout << var1 << " ";
	PR(var2...);
}
ifstream fin(IN_FILE);
ofstream fout(OUT_FILE);
int t, n, m;
VI start, fibo;
VB f;
vector <char> b;
int closestFibo(int nr)
{
	int i = 1;
	while (i <= 46 && fibo[i] < nr) ++i;
	if (i == 47) return -46;
	if (nr == fibo[i]) return i;
	else return nr - fibo[i - 1] <= fibo[i] - nr ? -(i - 1) : -i;
}
int main()
{
	fibo.RS(47);
	fibo[0] = 0;
	fibo[1] = 1;
	FOR(i, 2, 46) fibo[i] = fibo[i - 1] + fibo[i - 2];
	fin >> t >> n >> m;
	int k = n * m; 
    b.RS(k + 1); 
    FOR(i, 1, n) 
    {
		int x;
        FOR(j, 1, m) 
		{
			fin >> x;
			b[(j - 1) * n + i] = closestFibo(x);
		}
    } 
    fin.close();
	if (t == 1)
	{
		int cnt = 0;
		FOR(i, 1, k) cnt += b[i] > 0;
		fout << cnt;
	}
	else
	{
		start.PB(1);
		start.PB(1);
		f.PB(false);
		f.PB(b[1] > 0);
		int segments = 1;
		FOR(i, 2, k)
			if ((b[i] > 0) != (b[i - 1] > 0)) 
			{
				++segments;
				start.PB(i);
				f.PB(!f.back());
			}
		f.PB(false);
		f.PB(false);
		start.PB(n * m + 1);
		start.PB(start.back());
		int toChange = 0, best = 0;
		FOR(i, 1, segments)
			if (!f[i])
			{
				int aux = start[i + 2] - start[i - 1];
				if (aux > best)
				{
					best = aux;
					toChange = i;
				}
			}
		LL sum = 0;
		if (toChange)
		{
			FOR(i, start[toChange - 1], start[toChange + 2] - 1)
			{
				sum += fibo[abs(b[i])];
			}
		}
		else
		{
			FOR(i, 1, k)
			{
				sum += fibo[abs(b[i])];
			}
		}
		fout << sum;
	}
	fout.close();
	return 0;
}