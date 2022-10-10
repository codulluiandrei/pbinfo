#include <iostream>
using namespace std;
int main() {
    int a, b, temp;
    cin >> b >> a;
    temp = a;
    for (int i = 1; i < b; i++) {
        a = a + temp;
    } for (int i = 1; i <= b; i++) {
        cout << a << " ";
        a = a - temp;
    } return 0;
}