#include <bits/stdc++.h>
using namespace std;

ifstream in("proiecte.in");
ofstream out("proiecte.out");

int n, t;
struct proiect {
    int t, pozitie;
} v[1001];

int main() {
    in >> n;
    for (int i = 0; i < n; i++) {
        in >> v[i].t; v[i].pozitie = i + 1;
    } proiect temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (v[i].t > v[j].t) {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
    for (int i = 0; i < n; i++)
        out << v[i].pozitie << " ";

    return 0;
}