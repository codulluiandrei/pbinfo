#include <bits/stdc++.h>
using namespace std;
ifstream in("paresort.in");
ofstream out("paresort.out");
int n, m, var, v[1001];
int main() {
    in >> n;
    m = 0;
    for (int i = 1; i <= n; i++) {
        in >> var;
        if (var % 2 == 0) v[++m] = var;
    } for (int i = 1; i < m; i++)
        for (int j = i + 1; j <= m; j++)
        if (v[i] > v[j]){
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    } if (m == 0) out << "nu exista";
    else {
        out << m << endl;
        for (int i = 1; i <= m; i++)
            out << v[i] << " ";
    } return 0;
}