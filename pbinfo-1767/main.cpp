#include <bits/stdc++.h>
using namespace std;
ifstream in("multiple.in");
ofstream out("multiple.out");
#define cin in
#define cout out
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        long long int a, b, temp;
        cin >> a >> b;
        temp = b * (a / b + 1);
        cout << temp << "\n";
    } return 0;
}