#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int a, b, mini1 = 10, mini2 = 10, maxi1 = -1, maxi2 = -1;
    cin >> a >> b;
    maxi1 = max(a % 10, a / 10 % 10);
    maxi1 = max(maxi1, a / 100 % 10);
    maxi2 = max(b % 10, b / 10 % 10);
    maxi2 = max(maxi2, b / 100 % 10);
    mini1 = min(a % 10, a / 10 % 10);
    mini1 = min(mini1, a / 100 % 10);
    if (mini1 == 0) {
        if (b % 10 != 0 && b % 10 < mini2) mini2 = b % 10;
        if (b / 10 % 10 && b / 10 % 10 < mini2) mini2 = b / 10 % 10;
        if (b / 100 % 10 < mini2) mini2 = b / 100 % 10;
    } else {
        mini2 = min(b % 10, b / 10 % 10);
        mini2 = min(mini2, b / 100 % 10);
    } if (maxi1 > maxi2) cout << maxi1 << maxi2 << " ";
    else cout << maxi2 << maxi1 << " ";
    if (mini2 * 10 + mini1 > maxi1 * 10 + mini2) {
        cout << maxi1 << mini2;
        return 0;
    } if (mini1 == 0) cout << mini2 << mini1 << " ";
    else if (mini2 == 0) cout << mini1 << mini2 << " ";
	else if (mini1 > mini2) cout << mini2 << mini1 << " ";
	else cout << mini1 << mini2 << " ";
	return 0;
}