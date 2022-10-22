#include <bits/stdc++.h>
using namespace std;
ifstream in("cod24.in");
ofstream out("cod24.out");
#define cin in
#define cout out
long long int n, rez = 0;
int main() {
      cin >> n;
      int p = 1;
      int cif1 = n % 10;
      int cif2 = n / 10 % 10;
      int cif = n / 100 % 100;
      int n = cif * 100 + cif1 * 10 + cif2;
      while (n > 0) {
            int cif = n % 10;
            if (cif == 9)
                  rez = rez + cif * p;
            else if (cif < 9) {
                  cif++;
                  rez = rez + cif * p;
            }
            p = p * 10;
            n = n / 10;
      } cout << rez;
      return 0;
}