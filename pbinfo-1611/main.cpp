#include <bits/stdc++.h>
using namespace std;

ifstream in("palindrom2.in");
ofstream out("palindrom2.out");

int main() {
    int C, n, k, cond = 1, aproape = 0, palindrom = 0;
    long long nr, temp, temp2 = 0, val1, val2;
    in >> C >> n;
    for (int i = 1; i <= n; i++) {
        in >> nr;
        temp = nr; temp2 = k = 0;
        while (temp != 0) {
            temp2 = temp2 * 10 + temp % 10;
            k++;
            temp = temp / 10;
        }
        if (C == 1) {
            if (nr == temp2) palindrom++;
        } else if (C == 2) {
            val1 = nr, val2 = temp2, cond = 0;
            while (val1 && cond <= 2) {
                if (val1 % 10 != val2 % 10) cond++;
                    val1 = val1 / 10;
                    val2 = val2 / 10;
            } if (cond == 2) aproape++;
        } else {
            int var = 1;
            for (int j = 1; j <= k / 2; j++)
            var = var * 10;
            temp = nr / var * var + temp2 % var;
            if (temp <= nr) {
                if (k % 2 == 0) val1 = val2 = (nr / var + 1);
                else val1 = val2 = (nr / var + 1) / 10;
                temp2 = 0;
            while (val2 != 0) {
                temp2 = temp2 * 10 + val2 % 10;
                val2 = val2 / 10;
            } temp = (nr / var + 1) * var + temp2;
        } out << temp << " "; }
    }
    if (C == 1) out << palindrom;
    else if (C == 2) out << aproape;
    return 0;
}
