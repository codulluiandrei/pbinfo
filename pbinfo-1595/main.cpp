#include <bits/stdc++.h>
using namespace std;
ifstream in("bomboane1.in");
ofstream out("bomboane1.out");
#define cin in
#define cout out
int x, y, var = -1000, v = 0;
int main() {
      int a, b;
      cin >> x >> y;
      if (x % 2 == 1) x++;
      for (int i = x; i <= y; i = i + 2) {
            int copie = i, doi = 0, contor = 0;
            while (copie % 2 == 0) copie = copie / 2, doi++;
            int d;
            for (d = 1; d * d < copie; d = d + 2)
                  if (copie % d == 0) contor = contor + 2;
            if (d * d == copie) contor++;
            contor = contor * doi;
            if (contor > var)
                  var = contor, a = b = i, v = 1;
            else if (contor == var)
                  b = i, v++;
      } cout << a << " " << b << " " << v << " " << var;
      return 0;
}