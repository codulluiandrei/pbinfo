#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n % 4 != 0) {
        cout << "nebisect";
        return 0;
    } if (n % 400 == 0) {
        cout << "bisect";
        return 0;
    } if (n % 100 == 0) {
        cout << "nebisect";
        return 0;
    } if (n % 4 == 0) {
        cout << "bisect";
        return 0;
    } return 0;
}