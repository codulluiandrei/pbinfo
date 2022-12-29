#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int a, b, i, contor = 0;
    cin >> a >> b;
    i = sqrt(a);
    if (i * i < a) i++;
    for (; i * i <= b; i++) {
        int n = i * i, oglinda = 0;
        while (n)
            oglinda = 10 * oglinda + n % 10, n = n / 10;
        n = sqrt(oglinda);
        if(n * n == oglinda)
            contor++;
    } cout << contor;
    return 0;
}