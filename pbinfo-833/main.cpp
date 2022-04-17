#include <iostream>
using namespace std;
int main() {
    int a, b, dif;
    cin >> a >> b;
    dif = a - b;
    if (div > 0) cout << "Primul copil este mai mare cu " << dif << " ani";
    else if (dif < 0) cout << "Al doilea copil este mai mare cu " << -dif << " ani";
	else cout << "Copiii au varste egale";
    return 0;
}