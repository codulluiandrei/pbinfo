#include <iostream>
using namespace std;
int main() {
   int n, temp = 1;
   cin >> n;
   while (n % (temp * 10) == 0)
       temp = temp * 10;
   cout << n / temp;
   return 0;
}