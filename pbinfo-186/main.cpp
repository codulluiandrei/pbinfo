#include <iostream>
using namespace std;
int v[10];
int cifmin(int n) {
    int var = 10;
    while (n != 0) {
        if (n % 10 < var)
            var = n % 10;
        n = n / 10;
    } return var;
} int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v[cifmin(temp)]++;
    } int temp = 1;
    while (v[temp]==0) temp++;
    cout << temp;
    v[temp]--;
    for (int i = 0; i < 10; i++)
        for (int j = 1; j <= v[i]; j++) cout << i;
        return 0;
}