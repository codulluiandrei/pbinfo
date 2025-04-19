#include <iostream>
using namespace std;
int main() {
    long long int v[1001], n;
    bool adv = false;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (v[i] < v[j]) {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
    for (int i = 1; i <= n; i++)
        if (v[i] % 10 == 0) {
            cout << v[i] << " ";
            adv = true;
        }
    if (adv == false) 
        cout << "NU EXISTA";
    return 0;
}