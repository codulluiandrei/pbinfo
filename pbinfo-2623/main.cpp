#include <iostream>
#include <math.h>
using namespace std;
int n, v[100001], dreapta[100001], stanga[100001], temp = 0;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    stanga[1] = 1;
    for (int i = 2; i <= n; i++)
        stanga[i] = max(v[i], stanga[i - 1]);
    dreapta[n] = v[n];
    for (int i = n - 1; i >= 1; i--)
        dreapta[i] = min(v[i], dreapta[i + 1]);
    for (int i = 2; i < n; i++)
        if (stanga[i] == dreapta[i]) temp++;
    cout << temp << "\n";
    return 0;
}