#include <iostream>
using namespace std;
int main() {
    int a, b, s;
    cin >> a;
    s = a;
    cin >> b;
    while (a != b) {
        s = s + b;
        a = b;
        cin >> b;
    } s = s + b;
    cout << s; 
    return 0;
}