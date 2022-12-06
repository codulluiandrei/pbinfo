#include <iostream>
using namespace std;
int n, doi = 0, cinci = 0;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int temp;
        cin >> temp;
        while (temp % 2 == 0) {
                doi++;
                temp = temp / 2;
        } while (temp % 5 == 0) {
                cinci++;
                temp = temp / 5;
        }
    } if (doi > cinci) cout << cinci;
    else cout << doi;
    return 0;
}