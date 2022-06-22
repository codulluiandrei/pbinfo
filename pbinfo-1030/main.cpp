#include <iostream>
using namespace std;
long long int n, S = 0, t = 0, temp;
int main() {
    cin >> n;
    for(int i = 1; i <= n / 2; i++) {
        cin >> temp;
        S = S + temp;
    } for (int i = 1; i <= n / 2; i++) {
        cin >> temp;
        t = t + temp;
    } S = S * t;
    cout << S;
    return 0;
}