#include <iostream>
using namespace std;
int main() {
    int v[101], n, div2 = 0, poz2 = 0, div10 = 0, div3poz1 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for(int i = n; i > 0; i--)
        cout << v[i] << " ";
    cout << "\n";
    for (int i = 1; i <= n; i++) {
        if (v[i] % 2 == 0)
            div2 = div2 + v[i];
        if (i % 2 == 0)
            poz2 = poz2 + v[i];
        if (v[i] % 10 == 0)
            div10++;
        if (v[i] % 3 == 0 && i % 2 == 1)
            div3poz1 = div3poz1 + v[i];
    }
    cout << div2 << "\n";
    cout << poz2 << "\n";
    cout << div10 << "\n";
    cout << div3poz1;
    return 0;
}
