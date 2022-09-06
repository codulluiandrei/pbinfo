#include <iostream>
using namespace std;
int main() {
    int n, varminim = 1000000000, nrminim = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp, oglinda = 0;
        cin >> temp;
        int copie = temp;
        while (copie) {
            oglinda = 10 * oglinda + copie % 10;
            copie = copie / 10;
        } if (abs(temp - oglinda) < varminim) {
            varminim = abs(temp - oglinda);
            nrminim = temp;
        } else if (abs(temp - oglinda) == varminim)
                if (temp < nrminim)
                    nrminim = temp;
    } cout << nrminim;
    return 0;
}