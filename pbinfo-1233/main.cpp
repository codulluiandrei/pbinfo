/*
    prof. Constantin Galatan
    O(m)
    Mars's trick
*/
#include <fstream>
#include <vector>
std::ifstream fin("paint.in");
std::ofstream fout("paint.out");
int main()
{
	int n, m, k;
    fin >> n >> k >> m;
	std::vector<int> a(n + 3);
    for (int d(0), L(0); m--; a[++d]++, a[d + L]--)
        fin >> d >> L;
    int D(0);
    for (int i(0), cnt(0); i <= n; ++i) {
		cnt += a[i];
		if ( cnt < k ) D++;
	}
    fout << --D << '\n';
    fin.close();
    fout.close();
    return 0;
}