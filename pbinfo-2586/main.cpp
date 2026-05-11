#include <iostream>
using namespace std;
int n;
int main () {
    cin >> n;
    cout << ((n>>6) & 7);
    return 0;
}