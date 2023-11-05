#include <iostream>
using namespace std;
int main() {
    int n, contor = 1;
    cin >> n;
    do {
        contor++;
        if (n % 2 == 0)
            n = n / 2;
        else 
            n = 3 * n + 1;
    } while (n != 1);
    cout << contor;
    return 0;
}