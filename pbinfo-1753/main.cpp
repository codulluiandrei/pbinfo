#include <bits/stdc++.h>
using namespace std;

ifstream in("concurs2.in");
ofstream out("concurs2.out");

int main() {
    int C, N;
    in >> C >> N;
    if (C == 1) {
        int S, P1, P2;
        int peste0 = 0;
        for (int i = 0; i < N; i++) {
            in >> S >> P1 >> P2;
            if (P1 > 0 && P2 > 0) peste0++;
        } if (peste0 == N) out << "DA";
        else out << "NU";
    } if (C == 2) {
        int S, P1, P2;
        int gr1 = 0, gr2 = 0;
        for (int i = 0; i < N; i++) {
            in >> S >> P1 >> P2;
            if (S == 1) gr1++;
            if (S == 2)
            gr2++;
        } out << 1 << " " << gr1 << endl;
        out << 2 << " " << gr2;
    } if (C == 3) {
        int sectiune[500], punctaj[500], elevi[500];
        int elevi1 = 0, elevi2 = 0;
        int maxim1 = 0, maxim2 = 0;
        for (int i = 0; i < N; i++) {
            in >> sectiune[i] >> punctaj[i] >> elevi[i];
            if (sectiune[i] == 1) {
                if (punctaj[i] + elevi[i] > maxim1)
                    maxim1 = punctaj[i] + elevi[i];
            } if (sectiune[i] == 2) {
                if (punctaj[i] + elevi[i] > maxim2)
                    maxim2 = punctaj[i] + elevi[i];
            }
        } for (int i = 0; i < N; i++) {
            if (sectiune[i] == 1 && punctaj[i] + elevi[i] == maxim1) elevi1++;
            if (sectiune[i] == 2 && punctaj[i] + elevi[i] == maxim2) elevi2++;
        } out << "1 " << maxim1 << " " << elevi1 << endl;
        out << "2 " << maxim2 << " " << elevi2 << endl;
        out << elevi1 + elevi2;
    } return 0;    
}