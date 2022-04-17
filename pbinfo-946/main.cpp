#include <iostream>
using namespace std;
char carac[101];
int n = 0, temp, v[101];
int main() {
    cin >> carac;
    while (carac[n] >= '0' && carac[n] <= '9') {
        v[n] = carac[n] - '0';
        n++;
    } n--;
    if ((n + 1) % 2 == 1) {
        cout << 1;
        for (int i = 1; i < n; i = i + 2) { 
            temp = v[i] * 2 + v[i + 1];
            cout << temp;
        }
        ;
    } else for (int i = 0; i < n; i = i + 2)
        cout << v[i] * 2 + v[i + 1];
    return 0;
}