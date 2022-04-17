#include <iostream>
#include <math.h>
using namespace std;
bool prim(long long n) {
    long long int d;
    if (n == 0 or n == 1)
        return false;
    for (d = 2; d * d <= n; ++d)
    if (n % d == 0)
        return false;
    return true;
}
unsigned long long start,stop;
unsigned long long a, b, i, nr, p = 1;
int main() {
    cin >> a >> b;
    start = log2(a) + 1;
    stop = log2(b);
    for (int i = 1; i <= start; i++)
        p = p * 2;
    if (prim(start)) {
        nr = nr + p - a;
    } for (int i = start; i < stop; ++i)
        if (prim(i + 1)) { 
        nr = nr + p;
        p = p * 2;
    } else p = p * 2;
    if (prim(stop + 1)) 
        nr = nr + b - p + 1;
    cout << nr << " ";
    return 0;
}