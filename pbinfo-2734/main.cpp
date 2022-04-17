#include <iostream>
using namespace std;
int main() { 
    int v[1001], n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (v[i] == v[j]) {
                for (int k = j + 1; k <= n; k++)
                    v[k - 1] = v[k];
                n--;
                j--;
            }
    for (int i = 1; i <= n; i++) cout << v[i] << " ";
    return 0;
}
