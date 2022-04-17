#include <iostream>
using namespace std;
int main() {
    int a, b;
    char c;
    cin >> a >> b;
    cin >> c;
    if (c == '+') cout << a + b;
    else if (c == '*') cout << a * b;
    else if (c == '-') cout << max(a, b) - min(a, b);
    else if (c == '/') cout << max(a, b) / min(a, b);
    return 0;
}