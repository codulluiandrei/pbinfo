#include <bits/stdc++.h>
using namespace std;

ifstream in("fiboverif1.in");
ofstream out("fiboverif1.out");

bool fibo(int n) {
    if (n == 1) return true;
    int a = 1, b = 1, temp;
    while (b < n) {
        temp = a + b;
        a = b;
        b = temp;
    } if (b == n) return true;
    return false;
}
int main() {
    int n, x ;
    in >> n;
    while (n > 0) {
        in >> x;
        if (fibo(x)) out << x << " ";
        n--;
    } return 0;
}
