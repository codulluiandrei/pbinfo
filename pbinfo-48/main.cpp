#include <bits/stdc++.h>
using namespace std;
int main() {
  int temp, n, S; cin >> n;
  temp = sqrt(n);
  S = temp * (temp + 1) * (2 * temp + 1) / 6;
  cout << "Rezultatul este " << S;
  return 0;
}