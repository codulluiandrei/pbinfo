// Adrian Budau - 100 de puncte - Complexitate O(N)
#include <iostream>
#include <fstream>
using namespace std;
static const int kModulo = 1000 * 1000 * 1000 + 7;
int main() {
    ifstream cin("calc.in");
    ofstream cout("calc.out");
    int tip; cin >> tip;
    int N; cin >> N;
    string S; cin >> S;
    if (tip == 1) {
        int A = 1, B = 1;
        for (int i = 2; i <= N; ++i) {
            int C = (A + B) % kModulo;
            A = B; B = C;
        }
        cout << B << "\n";
        return 0;
    }
    if (N == 1) {
        cout << -1 << "\n" << -1 << "\n";
        return 0;
    }
    string prev = S, next = S;
    // predecessor
    if (S[N - 1] == '1' && S[N - 2] == '1')
        prev[N - 1] = prev[N - 2] = '0';
    else {
        int i;
        for (i = N - 2; i >= 0 && S[i] == '0'; --i);
        if (i < 0)
            prev = "-1";
        else {
            prev[i] = '0';
            for (i += 2; i < N; ++i)
                prev[i] = '1';
        }
    }
    // successor
    if (S[N - 1] == '0' && S[N - 2] == '0')
        next[N - 1] = next[N - 2] = '1';
    else {
        int i;
        for (i = N - 1; i >= 0 && S[i] == '1'; --i);
        if (i < 0)
            next = "-1";
        else {
            next[i - 1] = '1';
            next[i] = '0';
            int oldi = i;
            for (++i; i < N; ++i)
                next[i] = '0';
            if ((N - 1 - oldi) % 2 == 0)
                next[N - 1] = '1';
        }
    }
    cout << prev << "\n" << next << "\n";
}