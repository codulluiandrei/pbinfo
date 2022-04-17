#include <iostream>
using namespace std;
int main() {
   int n = 0, d = 1, div = 0;
   cin >> n;
   while (d * d < n) {
       if (n % d == 0) {
           div = div + 2;
       } d++;
   } if (d * d == n) div++;
   if (div % 2 == 1)
       cout << "da";
   else
       cout << "nu";
   return 0;
}
