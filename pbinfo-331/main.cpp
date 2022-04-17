#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int temp = (n * 2);
    for (int i = temp ; i >= 1 ; i-- ) {
        if (i % 2 == 1) cout << i << " ";
   	}
    return 0;
}