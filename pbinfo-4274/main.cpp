#include <iostream>
using namespace std;
int main() {
    int n;
    char carac;
    cin >> n >> carac;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            cout << carac;
        cout << "\n";
    }
    for (int i = n; i >= 1; i--) {
        for (int j = n; j > i; j--)
            cout << " ";
        for (int j = 1; j <= i; j++)
            cout << carac;
        cout << "\n";
    } return 0;
}