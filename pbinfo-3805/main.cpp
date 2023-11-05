#include <iostream>
#include <math.h>
using namespace std;
int main() {
   double a, b, c, p, R;
   cin >> a >> b >> c;
   if (a + b >= c && a + c >= b && b + c >= a) {
      p = (a + b + c) / 2;
      R = a * b * c / (4 * sqrt(p * (p - a) * (p - b) * (p - c))) * 100;
      cout << int(R) / 100 << "." << int(R) / 10 % 10 << int(R) % 10;
   } else cout << "Imposibil";
   return 0;
}