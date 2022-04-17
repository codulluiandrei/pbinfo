#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    for(int nr = 2 ; nr <= (n * 2) + 1 ; nr++ ) {
        if (nr % 2 == 0)
        	cout << nr << " ";
        }
    return 0;
}