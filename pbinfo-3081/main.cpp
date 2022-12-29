#include <iostream>
using namespace std;
bool prim(int x) {
    if (x < 2) return false;
    if (x != 2 && x % 2 == 0) return false;
    for (int d = 3; d * d <= x; d = d + 2)
        if (x % d == 0) return false;
	return true;
}
int nrcif(int x) {
    int contor = 0;
    while (x)
        contor++, x = x / 10;
    return contor;
}
int putere10(int x) {
    int contor = 1;
    for (; x; x--)
        contor = contor * 10;
    return contor;
}
void primacifra(int &n) {
    if (n < 9) {
        n = 0;
        return;
    } int cifre = nrcif(n);
    n = n % putere10(cifre - 1);
}
int main() {
    int n; cin >> n;
    bool adv = true;
    while (n) {
        if (!prim(n)) adv = false;
        primacifra(n);
    }
    if (adv) cout << "DA";
    else cout << "NU";
    return 0;
}