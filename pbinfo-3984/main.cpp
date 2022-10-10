#include <iostream>
using namespace std;
int main() {
    int a, b, temp;
    cin >> a >> b;
    temp = a;
    for (int i = 1; i <= b; i++) {
        cout << a << " ";
        a = a + temp;
    } return 0;
}