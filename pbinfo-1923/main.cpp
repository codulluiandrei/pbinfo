#include <bits/stdc++.h>
using namespace std;

ifstream in("egale.in");
ofstream out("egale.out");

int main() {
    int C; in >> C;
    if (C == 1) {
        long long a, b, temp = 1;
        in >> a >> b;
        while (temp <= b) {
            for (int i = 1; i <= 9; i++)
                if (a <= i * temp && i * temp <= b)
                    out << i * temp << " ";
            temp = temp * 10 + 1;
        }
    } else {
        int x; in >> x;
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= 9; j++) {
                for (int k = 1; k <= i; k++) out << j;
                out << " ";
            }
        }
    } return 0;
}