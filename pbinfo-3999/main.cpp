#include <iostream>
using namespace std;
int main() {
    long long int n, s = 0, x, y;
    cin >> n; 
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        s = s + min(x, y);
    } cout << s;
    return 0;
}