#include <iostream>
using namespace std;
int main() {
    int n, l, c;
    cin >> n;
    for (l = 1; l <= n; l++) {
        for (c = 1; c <= l; c++) cout << '*';
        for (c = 1; c <= 3 * n - 2 * l; c++) cout << ' ';
        for (c = 1; c <= l; c++) cout << '*';
        cout << "\n";
    } for (l = 1; l <= n; l++) {
        for (c = 1; c <= n; c++) cout << ' ';
        for (c = 1; c <= n; c++) cout << '*';
        cout << '\n';
    } for (l = 1; l <= n; l++) {
        for (c = 1; c <= n + 1 - l; c++) cout << '*';
        for (c = n + 1 - l; c < n; c++) cout << ' ';
        for (c = 1;c <= n; c++) cout << ' ';
        for (c = 1;c < l; c++) cout << ' ';
        for (c = l;c <= n; c++) cout << '*';
        cout << '\n';
    }
    return 0;
}