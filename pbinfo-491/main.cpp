#include <iostream>
using namespace std;
int main() {
    int n, v[1005];
    cin  >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    int a = -1, b = -1;
    for (int i = 0; i < n; i++)
        if (v[i] % 2 == 0) {
            if (a == -1) a = i;
            b = i;
        } if (a !=-1) {
        int S = 0;
        for (int i = a; i <= b; i++) S = S + v[i];
        cout << S;
    } else cout << "NU EXISTA";
    return 0;
}
