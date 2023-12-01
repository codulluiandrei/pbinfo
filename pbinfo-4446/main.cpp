/* Stud. Buca Mihnea-Vicentiu
   Facultatea de Matematica si Informatica
   O(vmx logvmx)
*/

#include <bits/stdc++.h>

using namespace std;

ifstream fin("magictrick.in");
ofstream fout("magictrick.out");

int cnt[500005], H[500005];
int c, n, x, d;

long long sumv[500005];
long long rez, sum, cmmdc = -1;

int main() {
    fin >> c >> n;
    /* cerinta 1 */
    if (c == 1) {
        for (int i = 0; i < n; ++i) {
            fin >> x;
            sum += x;
            if (cmmdc == -1) cmmdc = x;
            else {
                /* algoritmul lui euclid */
                int a = cmmdc, b = x, c;
                while (b) {
                    c = a % b;
                    a = b, b = c;
                }
                cmmdc = a;
            }
        }
        fout << cmmdc * sum;
        return 0;
    }

    /* cerinta 2 */
    for (int i = 0; i < n; ++i) {
        fin >> x;
        ++H[x];
    }

    for (int i = 1; i <= 500000; ++i)
        for (int j = i; j <= 500000; j += i) {
            cnt[i] += H[j];
            sumv[i] += (long long)H[j] * j;
        }

    /* gaseste rezultat */
    for (int i = 1; i <= 500000; ++i) { 
        if (cnt[i] >= 2 and sumv[i] * i > rez)  {
            rez = sumv[i] * i;
        }
    }
    fout << rez;
}