#include <iostream>
using namespace std;
int v[100001], n, temp, suma_maxim = 0;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> temp;
        v[i] = v[i - 1] + temp;
    } temp = v[n];
    for (int i = temp; i <= n; ++i)
        if (suma_maxim < (v[i] - v[i - temp]))
        	suma_maxim = v[i] - v[i - temp];
    cout << temp - suma_maxim;
    return 0;
}
