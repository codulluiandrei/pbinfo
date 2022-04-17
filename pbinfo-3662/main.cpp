#include <iostream>
using namespace std;
int main() {
   long long n, S = 0, nrcif;
   cin >> n;
   while (n > 0) {
       S = S + n % 10;
       n = n / 10;
   } nrcif = 1;
   while (S > 9) {
       nrcif++;
       S = S / 10;
   } cout << nrcif;
   return 0;
}