#include <bits/stdc++.h>
using namespace std;
int nr, var = 0, temp = 0;
int main() {
    cin >> nr;
    for (temp = 1; temp * temp < nr; temp++)
        if (nr % temp == 0)
          var = var + temp + nr / temp;
    if (temp * temp == nr) var = var + temp;
    if (var - nr == nr)  cout << nr << " este perfect";
	else cout << nr << " nu este perfect";
    return 0;
}
