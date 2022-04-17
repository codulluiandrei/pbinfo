#include <bits/stdc++.h>
using namespace std;

ifstream in("munti.in");
ofstream out("munti.out");

int main() {
    int N, temp;
    in >> N;
    long long int S = 0;
    for (int i = 0; i < N; i++) {
        in >> temp;
        S = S + temp;
    }
    if (S % N == 0) out << N;
    else out << N - 1;
}