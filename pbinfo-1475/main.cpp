#include <bits/stdc++.h>
using namespace std;
ifstream in("numere14.in");
ofstream out("numere14.out");
#define cin in
#define cout out
long long int n, S = 0;
int main() {
      cin >> n;
      for (int i = 1; i <= n; i++) {
            long long int temp, copie, contor = 0, nrcif = 0;
            cin >> temp;
            copie = temp;
            while (copie > 0) {
                  nrcif++;
                  copie = copie / 10;
            } nrcif = nrcif / 2 + 1;
            while (temp > 0) {
                  contor++;
                  if (nrcif == contor) {
                        if (temp % 10 % 2 == 1)
                              S = S + temp % 10;
                  } temp = temp / 10;
            }
      } cout << S;
      return 0;
}