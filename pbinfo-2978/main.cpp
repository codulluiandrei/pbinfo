#include <bits/stdc++.h>
using namespace std;

ifstream in("aur.in");
ofstream out("aur.out");

unsigned char v[900001];
unsigned long long maxim;
long long n, k, p, temp = 0, x, poz, C;

int nrcif(int n) {
    int nrcif = 0;
    while (n != 0) {
        nrcif++;
        n = n / 10;
    } return nrcif;
}
int oglindit(int n) {
    int nr = 0;
    while (n != 0) {
        nr = nr * 10 + n % 10;
        n = n / 10;
    } return nr;
}

int main() {
    in >> C;
    if (C == 1) {
        int S = 0;
        in >> n;
        for (int i = 1; i <= n; i++)
            in >> x, S = S + nrcif(x);
        out << S;
    }
    else if (C == 2) {
        in >> n >> k;
        for (int i = 1; i <= n; i++) {
            in >> x;
            int oglinda = oglindit(x);
            while (x % 10 == 0) {
                temp++;
                x = x / 10;
                if (temp == k) out << 0;
            }
            while (oglinda != 0) {
                temp++;
                if (temp == k) out << oglinda % 10;
                oglinda = oglinda / 10;
    } } }
    else {
        in >> n >> p;
        for (int i = 1; i <= n; i++) {
            in >> x;
            int oglinda = oglindit(x), l = 0;
            while (x % 10 == 0) l++, x = x / 10;
            while (oglinda != 0) {
                v[++poz] = oglinda % 10;
                oglinda = oglinda / 10;
            } while(l)
                v[++poz] = 0, l--;
        }
        for (int i = 1; i <= poz - p + 1; i++) {
            unsigned long long rez = 0;
            for (int j = 1; j <= p; j++)
                rez = rez * 10 + v[i + j - 1];
            if (rez > maxim) maxim = rez;
        } out << maxim;
    }
}
