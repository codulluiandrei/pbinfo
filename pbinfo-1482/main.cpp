#include <bits/stdc++.h>
using namespace std;
ifstream in("numar4.in");
ofstream out("numar4.out");
#define cin in
#define cout out
long long int n, contor = 0;
int verif(int c) {
      int contor = 0;
      if (c != 0)
            contor++;
      if (c != 2)
            contor++;
      if (c != 4)
            contor++;
      if (c != 6)
            contor++;
      if (c != 8)
            contor++;
      return contor;
}
int main() {
      cin >> n;
      while (n > 0) {
            int cif = n % 10;
            contor = contor + verif(cif);
            n = n / 10;
      } cout << contor;
      return 0;
}