#include <bits/stdc++.h>
using namespace std;
int main() {
    int nr1, nr2, nr3, minim = 0; cin >> nr1 >> nr2 >> nr3;
  	minim = nr1;
  	if (nr2 < minim) minim = nr2;
  	if (nr3 < minim) minim = nr3;
  	cout << minim;
  	return 0;
}