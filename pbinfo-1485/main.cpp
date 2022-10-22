#include <bits/stdc++.h>
using namespace std;
ifstream in("jumatate1.in");
ofstream out("jumatate1.out");
#define cin in
#define cout out
long long int n, js = 0, jd = 0, nrcif = 0, mid;
int main() {
      cin >> n;
      long long int copie = n;
      while (copie > 0) {
            nrcif++;
            copie = copie / 10;
      } if (nrcif % 2 == 0)
            mid = nrcif / 2;
      else
            mid = nrcif / 2 + 1;
      int p = 1;
      while (mid > 0) {
            jd = jd + n % 10 * p;
            p = p * 10;
            mid--;
            n = n / 10;
      } js = n;
      while (js != 0) {
            int r = jd % js;
            jd = js;
            js = r;
      } cout << jd;
      return 0;
}