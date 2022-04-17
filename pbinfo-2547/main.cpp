#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int contor = 0, a, b;
    cin >> a >> b;
    int x = sqrt(a), y = sqrt(b);
    if (sqrt(a) != floor(sqrt(a))) x++;
    for (int i = x; i <= y; i++) {
        bool adv = true;
        if (i < 2) adv = false;
        else if (i % 2 == 0 && i > 2) adv = false;
             else for (int d = 3; d * d <= i; d = d + 2)
                        if (i % d == 0) adv = false;
        if (adv) contor++;
    } cout << contor;
    return 0;
}