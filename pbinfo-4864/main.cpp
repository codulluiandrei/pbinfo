#include <bits/stdc++.h>
using namespace std;
ifstream fin("prodpozitiv.in");
ofstream fout("prodpozitiv.out");
int main()
{
    int n, a, answer, nrNegative, maxNegativ, i;
    fin >> n;
    answer = nrNegative = 0;
    maxNegativ = -1001;
    for (i = 1; i <= n; i++)
    {
        fin >> a;
        if (a == 0) answer++;
        else if (a < 0) { nrNegative++; maxNegativ = max(maxNegativ, a); }
    }
    if (nrNegative % 2 == 1) answer += (-maxNegativ + 1);
    fout << answer << "\n";
    fin.close();
    fout.close();
    return 0;
}