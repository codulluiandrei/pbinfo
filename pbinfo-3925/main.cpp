#include <iostream>
using namespace std;
int main() {
   long long int n, c, r, m;
   cin >> n >> c >> r;
   m = n / c * c;
   if (m + r > n) cout << m + r;
   else cout << m + c + r;
   return 0;
}