#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        int perechi = 1, nr = 2;
        while (temp > 1) {
            if (temp % nr == 0) {
                int val = 0;
                while (temp % nr== 0)
                    val++, temp = temp / nr;
                perechi = perechi * (2 * val + 1);
            } else nr++;
            if (temp > 1 && nr * nr > temp) {
                perechi = perechi * 3;
                break;
            }
        } cout << perechi << " ";
    } return 0;
}