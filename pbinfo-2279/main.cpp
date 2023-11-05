#include <iostream>
using namespace std;
int t, n, p;
int main() {
    cin >> t;
    while (t != 0) {
        int c1 = 0, c2 = 0;
        cin >> n >> p;
        for (int i = 1; i <= n; i++) {
            int temp;
            cin >> temp;
            if (p / 2 <= temp) c1++;
            else if (p / 10 >= temp) c2++;
        } if (c1 == 1 && c2 == 2)
            cout << "da\n";
        else 
            cout << "nu\n";
        t--;
    } return 0;
}