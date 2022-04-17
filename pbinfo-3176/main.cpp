#include <bits/stdc++.h>
using namespace std;
ifstream in("fibo0.in");
ofstream out("fibo0.out");
int N, a, b;
int main() {
    while (in >> a >> b)
        N = N + (b % a == 0);
    out << N;
}