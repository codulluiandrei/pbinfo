#include <bits/stdc++.h>
using namespace std;
int main() {
    int nr; cin >> nr;
    cout << nr / 100 + nr % 10 + nr / 10 % 10;
    return 0;
}