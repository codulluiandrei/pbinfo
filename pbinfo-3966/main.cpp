#include <iostream>
using namespace std;
unsigned int a, b, c;
bool adv = true;
int main() {
    cin >> a >> b;
    c = a + b;
    while (a + b) {
        if (a % 10 + b % 10 > 9)
            adv = false;
        a = a / 10;
        b = b / 10;
    } if (adv == true) cout << "Gigel stie!";
    else cout << "Gigel nu stie! El poate cumpara " << c << " bomboane!";
    return 0;
}