#include <iostream>
using namespace std;
int calc_putere(int A, int B) {
    int P = 1;
    while (B) {
        P = P * A;
        B--;
    } return P;
}
int main() {
    int A, B;
    cin >> A >> B;
    cout << calc_putere(A, B);
}