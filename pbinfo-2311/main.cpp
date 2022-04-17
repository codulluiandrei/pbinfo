#include <bits/stdc++.h>
using namespace std;

ifstream in("rapunzel.in");
ofstream out("rapunzel.out");

int main() {
    long long N, M1, M2, zile;
    in >> N >> M1 >> M2;
    zile = M1 + M2;
    if (zile > N) out << 1;
    else if(N % zile == 0) out << N / zile;
    else out << N / zile + 1;
    return 0;
}