#include <bits/stdc++.h>
using namespace std;
ifstream in("intersectie.in");
ofstream out("intersectie.out");
int a[100005], b[100005], c[100005], ct, ct2, ct3, i, j;
int main() {
    a[0] = 1;
    while (a[ct] != 0) in >> a[++ct];
    ct--;
    while (in >> b[1]) {
        ct2 = 1;
        ct3 = 0;
        while (b[ct2] != 0) in >> b[++ ct2];
        i = j = 1;
        while (i <= ct && j <= ct2) {
            if (a[i] == b[j]) c[++ ct3] = b[j], j++, i++;
            else if (a[i] > b[j]) j++;
            else i++;
        } for (i = 1; i <= ct3; i++) a[i] = c[i];
        ct = ct3;
        if (ct3 == 0) { out << "nu exista"; return 0; }
    } for (i = 1; i <= ct3; i++) out << a[i] << " ";
    return 0;
}