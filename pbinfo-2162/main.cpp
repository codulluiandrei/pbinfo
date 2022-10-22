#include <bits/stdc++.h>
using namespace std;
ifstream in("conturi.in");
ofstream out("conturi.out");
#define cin in
#define cout out
long long int n, x, maxim = -1;
int main() {
      cin >> n >> x;
      for (int i = 1; i <= n; i++) {
            long long int temp;
            cin >> temp;
            int banca = temp / 100000;
            bool adv = false;
            if (temp / 10000 % 10 == 1)
                  adv = true;
            if (adv == true && temp % 10000 > maxim && banca == x)
                  maxim = temp % 10000;
      } cout << maxim;
      return 0;
}