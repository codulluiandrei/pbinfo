#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n % 2 == 0) cout<<"NU ESTE NOROCOS";
    else {
        int k = (n + 1) / 2;
        while (n != 0) {
            cout << k << " ";
            k++;
            n--;
        }
    } return 0;
}