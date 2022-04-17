#include <iostream>
using namespace std;
int n, temp, v[1501];
int main() {
    cin >> n >> temp;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = temp; i < n; i++) v[i] = v[i + 1];
    n --;
    for (int i = 1; i <= n; i++) cout << v[i] << " ";
    return 0;
}
