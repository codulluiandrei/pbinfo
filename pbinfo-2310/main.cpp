#include <bits/stdc++.h>
using namespace std;
ifstream in("saci.in");
ofstream out("saci.out");
#define cin in
#define cout out
long long int n, contor = 0, temp;
int main() {
      cin >> n;
      for (int i = 1; i <= n; i++) {
            bool adv = true;
            cin >> temp;
            if (temp > 9) {
                  while (temp > 9) {
                        int maxim = temp % 10;
                        if (maxim <= temp / 10 % 10)
                              adv = false;
                        temp = temp / 10;
                  }
            } if (adv)
                  contor++;
      } cout << contor;
      return 0;
}