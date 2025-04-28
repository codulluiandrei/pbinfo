/* 
	prof. Constantin Galatan
	Complexitate O(2^(n/2))
*/
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
ifstream fin("piese1.in");
ofstream fout("piese1.out");
int main()
{
	int n;
	long long  T;
	fin >> n >> T;
	vector<int> p(n);
	for (int i = 0; i < n; ++i)
		fin >> p[i];
	vector<long long>  x, y;
    int nx = n / 2;
    int ny = n - nx;
    for (int i = 0; i < (1 << nx); i++)
    {
		x.push_back(0);
		for (int j = 0; j < nx; j++)
			if ((1 << j) & i)            // daca setul i are bitul j
				x[x.size() - 1] += p[j];
    }
    for (int i = 0; i < (1 << ny); i++)
    {
		y.push_back(0);
		for (int j = 0; j < ny; j++)
			if ((1 << j) & i)
				y[y.size() - 1] += p[nx + j];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
	int res = 0;
    for (int i = 0; i < x.size(); i++)
    {
		int l = 0, r = y.size() - 1, m, pos = 0;
		while (l <= r)
		{
			m = (l + r) / 2;
			if (x[i] + y[m] <= T)
			{
				pos = m;
				l = m + 1;
			}
			else
				r = m - 1;
		}
		if (x[i] <= T)    
			res += pos + 1;
    }
	fout << res - 1;
	fin.close();
	fout.close();
}