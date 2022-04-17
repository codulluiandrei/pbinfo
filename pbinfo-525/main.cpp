#include <iostream>
using namespace std;
int freq[1001], nr, nr1 = 0, nr2 = 0, temp;
int main() {
    cin >> nr;  
    for (int i = 1; i <= nr; i++) {
        cin >> temp;
        if (temp > 99 && temp < 1000) freq[temp] = 1;
    }
    for (int t = 999; t > 99 && nr1 == 0; t--)
        if (freq[t] == 0)
            if (nr2 == 0) nr2 = t;
            else nr1 = t;
    if (nr1 != 0) cout << nr1 << " " << nr2;
    else cout << "NU EXISTA";
    return 0;
}