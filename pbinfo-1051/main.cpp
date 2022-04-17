#include <bits/stdc++.h>
using namespace std;

ifstream in("bete1.in");
ofstream out("bete1.out");

int main() {
    int n, ana[10000], bogdan[10000], L = 0, K = 0, P = 0, S = 0; in >> n;
    for(int i = 0; i < n; i++) {
        in >> ana[i];
        S = S + ana[i];
    }
    for(int i = 0; i < n; i++) {
        in >> bogdan[i];
        S = S + bogdan[i];
    }
    sort(ana, ana + n);
    sort(bogdan, bogdan + n);
    L = S / n;
    K = ana[n - 1] + bogdan[n - 1];
    int maxim = K;
    for (int i = n - 1; i >= 0; i--) {
        if (ana[i] + bogdan[i] == maxim) P++;
    }
    out << L << endl;
    out << K << endl;
    out << P;
    return 0;    
}