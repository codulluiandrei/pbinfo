#include <bits/stdc++.h>
using namespace std;
int n, b[100];
long long v[100], p[100];
ifstream in("becuri1.in");
ofstream out("becuri1.out");
void numarare(long long p[100]) {
    int cp;
    for (int i = 0; i < n; i++) {
        p[i] = 1;
        cp = v[i];
        if (cp == 0) p[i] = 1;
        else {
            while (cp != 0) {
                p[i] = p[i] * 10;
                cp = cp / 10;
            } p[i] = p[i] / 10;
} } }
void cerinta_1(long long v[100], int n) {
    int ca = 0;
    numarare(p);
    for (int i = 0; i < n; i++)
        if (v[i] / p[i] == 2 || v[i] / p[i] == 3 || v[i] / p[i] == 5 || v[i] / p[i] == 7)
        ca++;
        out << ca;
} void cerinta_2(long long v[100], int n) {
    int c = 0, maxbec, maxp = 0;
    numarare(p);
    for (int i = 0; i < n; i++) {
        if (p[i] > maxp) maxp = p[i];
        if (v[i] / p[i] == 2 || v[i] / p[i] == 3 || v[i] / p[i] == 5 || v[i] / p[i] == 7) c++;
    } maxbec = c;
    while (maxp!=1) {
        c = 0;
        for(int i = 0; i < n; i++) {
            v[i] = v[i] % p[i] * 10 + v[i] / p[i];
            if (v[i] / p[i] == 2 || v[i] / p[i] == 3 || v[i] / p[i] == 5 || v[i] / p[i] == 7) c++;
        } if (c > maxbec) maxbec = c;
        maxp = maxp / 10;
    } out << maxbec;
} void cerinta_3(long long v[100], int n) {
    int maxp = 0;
    numarare(p);
    for (int i = 0; i < n; i++) {
        if (p[i] > maxp) maxp = p[i];
        if (v[i] / p[i] == 2 || v[i] / p[i] == 3 || v[i] / p[i] == 5 || v[i] / p[i] == 7) b[i]++;
    } while (maxp != 1) {
        for (int i = 0; i < n; i++) {
            v[i] = v[i] % p[i] * 10 + v[i] / p[i];
            if (v[i] / p[i] == 2 || v[i] / p[i] == 3 || v[i] / p[i] == 5 || v[i] / p[i] == 7) b[i]++;
        } maxp/=10;
    } maxp = 0;
    for (int i = 0; i < n; i++)
        if (b[i] > maxp)
        maxp = b[i];
        if (maxp == 0)
        out << -1 <<" ";
        else for(int i = 0; i < n; i++)
            if (b[i] == maxp) out << i + 1 << " ";
} int main() {
    int C;
    in >> C >> n;
    for (int i = 0; i < n; i++)
        in >> v[i];
    if (C == 1) cerinta_1(v, n);
    else if (C == 2) cerinta_2(v, n);
    else if (C == 3) cerinta_3(v, n);
    return 0;
}
