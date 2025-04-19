#include <bits/stdc++.h>
using namespace std;
ifstream fin("cub.in");
ofstream fout("cub.out");
int i, j, nr, n, x, mul, crtState[4], states[100];
long long sol;
const int divs[] = {2, 3, 5, 7};
int convert() {
    return crtState[3] * 3 * 3 * 3 + crtState[2] * 3 * 3 + crtState[1] * 3 + crtState[0];
}
int main()
{
    fin >> n;
    for (i = 1 ; i <= n ; i++) {
        fin >> x;
        for (j = 0 ; j < 4 ; j++) {
            nr = 0;
            while (x % divs[j] == 0) {
                nr++;
                x /= divs[j];
                crtState[j]++;
            }
            crtState[j] %= 3;
        }
        states[convert()]++;
    }
    states[0]++;
    for (i = 0 ; i < 81 ; i++)
        sol += states[i] * (states[i] - 1) / 2;
    fout << sol;
    return 0;
}