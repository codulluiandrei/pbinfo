#include <bits/stdc++.h>
using namespace std;
ifstream in("pozne.in");
ofstream out("pozne.out");
#define cin in
#define cout out
long long int cer, n, s, c;
bool v[1000001];
void fciur() {
    v[0] = v[1] = true;
    for (int j = 4; j <= 99999; j = j + 2)
        v[j] = true;
    for (int i = 3; i * i <= 99999; i = i + 2)
        if (!v[i])
            for (int j = i * i; j <= 99999; j = j + 2 * i)
                v[j] = true;
}
long long int ogl(int n) {
    int oglinda = 0;
    while (n > 0) {
        oglinda = oglinda * 10 + n % 10;
        n = n / 10;
    } return oglinda;
}
bool verifcif(long long int a, long long int b) {
    while (a > 0) {
        if (a % 10 == b)
            return true;
        a = a / 10;
    } return false;
}
int main() {
    cin >> cer;
    cin >> n >> s >> c;
    if (cer == 1) {
        for (int i = 1; i <= n; i++) {
            long long int temp;
            cin >> temp;
            if (verifcif(temp, c))
                cout << temp << " ";
        }
    } else if (cer == 2) {
        int var = 0, contor = 0;
        for (int i = 1; i <= n; i++) {
            fciur();
            long long int temp;
            cin >> temp;
            long long int oglinda = ogl(temp);
            if (v[oglinda] == false) {
                contor++;
                if (verifcif(temp, c))
                    var = var - s;
                else
                    var = var + s;
            }
        } cout << contor << " ";
        if (var > 0)
            cout << 1;
        else if (var < 0)
            cout << -1;
        else if (var == 0)
            cout << 0;
    }
    return 0;
}