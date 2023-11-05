#include <iostream>
using namespace std;
int main() {
    int n, k, S = 0, contor = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        if (temp % 2 != 0)
            S = S + temp;
        if (temp % k == 0)
            contor++;
    } cout << S << " " << contor;
    return 0;
}