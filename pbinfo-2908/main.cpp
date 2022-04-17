#include <bits/stdc++.h>
using namespace std;

ifstream in("planta.in");
ofstream out("planta.out");

int main() {
    int D, A, B, N;
    in >> D >> A >> B >> N;
    long long int rezultat = D;
    if (N % 2 == 0) rezultat = rezultat + N / 2 * (A - B);
    else rezultat = rezultat + N / 2 * (A - B) + A;
    out << rezultat;
    return 0;
}