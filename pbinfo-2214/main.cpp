#include <bits/stdc++.h>
using namespace std;
int main () {
    int n, m, nr1, nr2, temp = 0, temp1 = 0, temp2 = 0;
    bool adv;
    cin >> n >> m; nr1 = n; nr2 = m;
    if (nr1 == 0) temp = 1;
    while (n != 0) {
        n = n / 10;
        temp1++;
    } while (m != 0) {
        m = m / 10;
        temp2++;
    } if (temp1 == temp2) {
        cout << "DA" << endl;
        adv = true;
    } else  {
        cout << "NU";
        adv = false;
    } if (adv == true) {
        while (nr1 != 0) {
            if (nr1 % 10 == nr2 % 10) {
                temp++;    
            } nr1 = nr1 / 10;
            nr2 = nr2 / 10;
        } cout << temp;
    } return 0;    
}