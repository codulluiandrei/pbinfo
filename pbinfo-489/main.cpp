#include <iostream>
using namespace std;
int main() {
    int n, v[1001];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    int i = 1, j = n;
    while (i <= j) {
        cout << v[i] << " ";
        if (i != j) cout << v[j] << " ";
        i++;
        j--;
    } return 0;

}