#include <bits/stdc++.h>
using namespace std;

ifstream in("plimbare.in");
ofstream out("plimbare.out");

int oglindit(int nr) {
    int oglinda = 0;
    int temp = nr;
    while (nr != 0) {
        oglinda = oglinda * 10 + nr % 10;
        nr = nr / 10;
    } if (temp == oglinda) return 1;
    else return 0;
}

int main() {
    int n, v[7001], temp = 0;
    in >> n;
    for (int i = 1; i <= n; i++) in>> v[i];
    for (int i = 1; i <= n; i++)
        if (oglindit(v[i]) == 1) temp++;
    out << temp;
    return 0;
}
