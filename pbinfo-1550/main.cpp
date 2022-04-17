#include <iostream>
using namespace std;
int main() {
    int v[101], n, fact = 1, temp = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    } for (int i = 1; i <= n; i++) 
        cin >> v[i];
    for (int i = 1; i <= n; i++) {
        if (fact % v[i] == 0)
            cout << v[i] << " ";
        temp++;
    } if (temp == 0) cout << "Nu exista!";
    return 0;
}