#include <iostream>
using namespace std;
int n, temp, x[1005];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
    cin >> temp;
    for (int i = 0; i < temp; --temp) {
        int a, b = -1;
        cin >> a;
        for (int i = 0; i < n && b == -1; i++)
            if (x[i] == a) b = i;
        if (b == -1) cout << "0 ";
        else cout << "1 ";
    } return 0;
}