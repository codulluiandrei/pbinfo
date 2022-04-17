#include <iostream>
using namespace std;
int main() {
    int n, pare = 0, impare = 0;
    cin >> n;
    for (int i = n; n >= 1; --n) {
        int temp; cin >> temp;
        if (temp == 0) pare++;
        else while (temp != 0) {
            if (temp % 2 == 0) pare++;
            else impare++;
            temp = temp / 10;
        }
    } cout << pare << " " << impare;
    return 0;
}