#include <iostream>
using namespace std;
int main() {
    int n; char c, d;
    cin >> n >> c >> d;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            if ((i + j) % 2 == 0) cout << c;
            else cout << d;
        cout << endl;
    } return 0;
}