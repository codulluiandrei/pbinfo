#include <iostream>
using namespace std;
int main() {
    long long n, perechi = 0, nr;
    cin >> n >> nr;
    for (int i = 1; i < n; i++) {
            int nrtemp = nr;
            cin >> nr;
            int temp = nr, var = nrtemp;
            int s1 = 0, s2 = 0;
            while (temp != 0) {
                s1 = s1 + temp % 10;
                temp = temp / 10;
            }
            while (var != 0) {
                s2 = s2 + var % 10;
                var = var / 10;
            } if (s1 == s2) perechi++;
    } cout << perechi;
    return 0;
}