#include <bits/stdc++.h>
using namespace std;

ifstream in("af.in");
ofstream out("af.out");

int main() {
   char semn, egal;
   long long int nr1, nr2, nr3, n;
   bool adv = 0;
   in >> n;
   for (int i = 1; i <= n; i++) {
      adv = 0;
      in >> nr1 >> semn >> nr2 >> egal >> nr3;
      if (adv == 0 && semn == '+' && nr1 + nr2 == nr3) adv = 1;
      if (adv == 0 && semn == '-' && nr1 - nr2 == nr3) adv = 1;
      if (adv == 0 && semn == 'x' && nr1 * nr2 == nr3) adv = 1;
      if (adv == 0 && semn == ':') {
           if (nr2 == 0) adv = 0;
           else if (nr1 / nr2 == nr3) adv = 1;
      } if (adv) out << "Adevarat" << "\n";
        else out << "Fals" << "\n";
   } return 0;
}