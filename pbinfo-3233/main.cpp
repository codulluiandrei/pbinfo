#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int temp = n - ((n+1) % 2);
    for (int i = temp; i >= 1; i -= 2)
        cout << i << " ";
    return 0;   
}