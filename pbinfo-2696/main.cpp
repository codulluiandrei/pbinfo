#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    if (a %  2 == b % 2)
        cout << (a / 10 % 2 == 0) + (a % 2 == 0) 
        		+ (b / 10 % 2 == 0) + (b % 2 == 0);
    else cout << a / 10 % 2 + a % 2 + b / 10 % 2 + b % 2;
    return 0;
}