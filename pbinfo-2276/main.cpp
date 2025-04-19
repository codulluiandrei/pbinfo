#include <iostream>
#include <algorithm>
using namespace std;
int v[200003], n;
int cb1(int x) {
    if (v[n] < x) return n + 1;
    if (x <= v[1]) return 1;
    int stanga, dreapta, mijloc, p;
    stanga = 1; dreapta = n; p = 1;
    while (stanga <= dreapta) {
    	mijloc = (stanga + dreapta) / 2;
        if (x <= v[mijloc]) {
            p = mijloc; dreapta = mijloc - 1;
        } else stanga = mijloc + 1;
    } return p;
}
int cb2(int y) {
    if (v[n] <= y) return n;
    if (v[1] > y) return 0;
    int stanga, dreapta, mijloc, p;
    stanga = 1; dreapta = n; p = 1;
    while (stanga <= dreapta) {
    	mijloc = (stanga + dreapta) / 2;
        if (v[mijloc] <= y) {
            p = mijloc; stanga = mijloc + 1;
        } else dreapta = mijloc - 1;
    } return p;
}
int main() {
    int i, p, q, T, x, y;
    cin >> n >> T;
    for (i = 1; i <= n; i++)
        cin >> v[i];
    sort(v + 1, v + n + 1);
    while (T--) {
        cin >> x >> y;
        p = cb1(x);
        q = cb2(y);
        cout << (q - p + 1) << "\n";
    } return 0;
}