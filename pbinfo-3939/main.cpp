#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
ifstream fin("intervale6.in");
ofstream fout("intervale6.out");
int v[10001];
int n, x, y, st, dr, mij, ans, ct;
int main() {
    fin >> n;
    for(int i = 1;i <= n;i++) 
        fin >> v[i];
    while(fin >> x >> y) {
        st = 1, dr = n;
        ans++;
        while(st <= dr) {
            mij = (st + dr) / 2;
            if(v[mij] >= x && v[mij] <= y) dr = st - 1, ct++;
            else if(v[mij] > y) dr = mij - 1;
            else if(v[mij] < x) st = mij + 1;
        }
    }
    fout << ans - ct;
    return 0;
}