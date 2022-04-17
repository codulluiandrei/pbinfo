#include <iostream>
using namespace std;
int main() {
    int n; char caracter;
    cin >> n >> caracter;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= i; ++j)
            cout << caracter;
        cout << "\n";
    } return 0;
}