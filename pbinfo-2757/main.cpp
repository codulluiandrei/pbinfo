#include <iostream>
using namespace std;
int n, c;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        if (temp % 3 == 0) c = (temp % 300 / 3 + 9) % 10;
        else if (temp % 3 == 1) c = temp / 300 + 1;
        else c = temp % 300 / 30 ;
        cout << c << " ";
    } return 0;
}