#include <iostream>
using namespace std;
int n, k, v[10001];
bool adv;
int main() {
   cin >> n >> k;
   for (int i = 1; i <= n; ++i)
	   cin >> v[i];
   for (int i1 = 1; i1 < k; ++i1) {
       int i = (i1 - 1) * (n / k) + 1;
       for (int j1 = i1 + 1; j1 <= k; ++j1) {
           int j = (j1 - 1) * (n / k) + 1;
           adv = true;
           for (int p = 0; p < n / k; ++p) {
               if (v[i + p] != v[j + p]) {
            	   adv = false;
            	   break;
               }
           } if (adv == true) {
               cout << i1 << " " << j1;
               return 0;
           }
       }
   } if (adv == false)
	   cout << "NU";
   return 0;
}
