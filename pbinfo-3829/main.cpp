#include <iostream>
using namespace std;
int n;
int main() {
    cin >> n;
    for (int j = 0; j < n - 1; ++j) {
        for (int i = j + 1; i < n; ++i)
            cout << '#';
        for (int i = 0; i < j * 2 + n; ++i)
            cout << '*';
        for (int i = j + 1; i < n; ++i)
            cout << '#';
        cout << "\n";
    } for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n * 3 - 2; ++j)
            cout << '*';
        cout << "\n";
    } for (int j = 0; j < n - 1; ++j) {
        for (int i = n - j - 1; i < n; ++i)
            cout << '#';
        for (int i = 0; i < (n - j - 1) * 2 + n - 2; ++i)
            cout << '*';
        for (int i = n - j - 1; i < n; ++i)
            cout << '#';
        cout << "\n";
    } return 0;
}