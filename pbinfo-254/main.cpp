#include <iostream>
using namespace std;
int main() {
    int n, a, b, p;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b;
        if (a > b) {
            int temp = a; 
            a = b, b = temp;        
        } p = 1;
        while (2 * p <= b) p = p * 2;
        if (p >= a)
            cout << p << "\n";
        else 
            cout << "0\n";
    } return 0;
}