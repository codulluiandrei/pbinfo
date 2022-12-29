#include <iostream>
using namespace std;
int main() {
    long long int a, b, contor = 0;
    cin >> a >> b;
    while (a != 0 && b != 0) {
        long long int x = a, y = b;
        long long int pa  = 1, pb = 1;
        while (x) 
            pa = pa * 10, x = x / 10;
        while (y) 
            pb = pb * 10, y = y / 10;
        long long int p, q, oglinda;
        p = q = a * pb + b, oglinda = 0;
        while (p != 0)
            oglinda = 10 * oglinda + p % 10, p = p / 10;
        if (oglinda == q)
            contor++;
        else {
            p = q = b * pa + a, oglinda = 0;
            while (p != 0)
                oglinda = 10 * oglinda + p % 10, p = p / 10;
            if (oglinda == q) contor++;
        } cin >> a >> b;
    } cout << contor << endl;
    return 0;
}