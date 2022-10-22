#include <iostream>
using namespace std;
int main() {
    int n, v[222], contor = 0;
    cin >> n;  
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    for (int i = 0; i < n; ++i) {
        int a = v[i], b = v[n - 1];
        if (b == 0) b = a;
        else while (a % b != 0) {
                int r = a % b;
                a = b;
                b = r;
            }
        if (b == 1) contor++;
    } cout << contor;
    return 0;
}