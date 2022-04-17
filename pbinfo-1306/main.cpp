#include <iostream>
using namespace std;
int main() {
    long long int n, temp, S = 0;
    cin >> n;
    while (n--) {
        cin >> temp;
        while (temp) {
            int cif = temp % 10;
            S = S + cif * cif * cif;
            temp = temp / 10;
        }
    } cout << S;
    return 0;
}