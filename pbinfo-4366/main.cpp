#include <iostream>
using namespace std;

const int NMAX = 1e6 + 5;
char s[NMAX];

void Cerinta1() {
    int n, op = 0;
    cin >> n;
    cin >> (s + 1);

    // calculam numarul de subsecvente ce contin numai |0>
    s[0] = -1;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == s[i - 1])
            continue;
        else if (s[i] == '0')
            ++op;
    }
    cout << op << "\n";
}

bool inv[NMAX];
void Cerinta2() {
    int n, k, op = 0;
    cin >> n >> k;
    cin >> (s + 1);

    // initializam vectorul inv
    for (int i = 1; i <= n; ++i)
        inv[i] = 0;
    bool is_inv = 0;

    for (int i = 1; i <= n; ++i) {
        // is_inv = 1 daca operatiile precedente au inversat qubitul
        if (inv[i])
            is_inv = !is_inv;
        
        bool bit = s[i] - '0';
        if (is_inv)
            bit = !bit;
        // qubitul este |0> 
        if (!bit) {
            // trebuie sa efectuam operatia
            if (i <= n - k + 1) {
                ++op;
                is_inv = !is_inv;
                inv[i + k] = !inv[i + k];
            }
            // caz imposibil
            else {
                op = -1;
                break;
            }
        }
    }
    cout << op << "\n";
}
int main() {
    int c, t;
    cin >> c >> t;
    while (t--) {
        if (c == 1)
            Cerinta1();
        else Cerinta2();
    }
    return 0;
} 