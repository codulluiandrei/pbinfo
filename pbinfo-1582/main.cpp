#include <iostream>
using namespace std;
int sumcif(int n) {
    int s = 0;
    while (n > 0) {
        s = s + n % 10;
        n = n / 10;
    } return s;
}
int main() {
    int n, sminim = 10000, smaxim = -1, minim = 10000000, maxim = -1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        int stemp = sumcif(temp);
        if (stemp > smaxim) {
            maxim = temp;
            smaxim = stemp;
        } if (stemp < sminim) {
            minim = temp;
            sminim = stemp;
        }
    } cout << minim << "\n" << maxim;
    return 0;
}