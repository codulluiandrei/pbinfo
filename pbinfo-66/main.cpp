#include <bits/stdc++.h>
using namespace std;
int main() {
  int nr, nrcif = 0; cin >> nr;
  do {
	nrcif++;
    nr = nr / 10;
  } while(nr);
  cout << nrcif;
  return 0;
}