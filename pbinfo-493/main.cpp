#include <iostream>
using namespace std;
int main() {
    int n, x[205], y[205];
    cin >> n;  
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    for (int  i = 0; i < n; ++i) {
        int a = x[i], s = 0;
        while (a)
            s = s + a % 10, a = a / 10;
        y[i] = x[i] % s;
    } for (int i = 0; i < n; ++i)
        cout << y[i] << " ";
    return 0;
}