#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    if (n % 6 == 0) 
        cout << n / 6 << " " << n / 3 << " " << n / 2;
    else 
        cout << "nu exista";
    return 0;
}