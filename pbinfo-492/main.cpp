#include <iostream>
using namespace std;
int main() {
    int n, v[222];
    cin >> n;  
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    int contor = 0;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int a = v[i], b = v[j];
        if (b == 0) b = a;
        else while(a % b != 0) {
                int r = a % b;
                a = b;
                b = r;
            }
        if (b == 1) contor++;
    } cout << contor;
    return 0;
}