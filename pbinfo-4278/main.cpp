#include <iostream>
using namespace std;
int main() {
    int temp, S = 0, contor = 0;
    cin >> temp;
    while (temp != 0) {
        if (temp % 2 == 0)
            S = S + temp;
        if (temp < 100 && temp > 9)
            contor++;
        cin >> temp;
    } cout << S << " " << contor;
    return 0;
}