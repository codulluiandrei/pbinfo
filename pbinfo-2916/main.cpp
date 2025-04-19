#include <bits/stdc++.h>
using namespace std;
ifstream fin("triviador.in");
ofstream fout("triviador.out");
int n, x, y, z, s, max1, max2;
int main() {
    fin >> n;
    for (int i = 1; i <= n; ++ i){
        fin >> x >> y >> z;
        s = x + y + z;
        if (s > max1) max2 = max1, max1 = s;
        else if (s > max2 && s != max1) max2 = s;
    }
    if (max2 == 0) fout << "TOTI SUNT CASTIGATORI";
    else fout << max1 << ' ' << max2;
    return 0;
}