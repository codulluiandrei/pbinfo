#include <iostream>
using namespace std;
int main() {
	int a, b;
    cin >> a >> b;
    if (a / 10 % 10 == b / 10 % 10)
        cout << a + b;
   	else if (a / 10 % 10 > b / 10 % 10)
        cout << a;
	else if (a / 10 % 10 < b / 10 % 10)
        cout << b;
}