#include <iostream>
using namespace std;
int main() {
    int S, d, r, m;
    cin >> S >> d >> r >> m;
    if (S >= d) cout << "drona";
    else if (S >= r) cout << "robot";
        else if (S >= m) cout << "masina";
            else cout << "nimic";
    return 0;
}