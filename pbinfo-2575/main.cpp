#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        long long int temp; cin >> temp;
        long long int rez = 0, counter = 1, p = 1;
        int ultima, prima;
        while (temp) {
            if (counter == 1) {
                ultima = temp % 10;
            	temp = temp / 10;
            } if (temp < 10) {
                prima = temp % 10;
                temp = temp / 10;
            } else {
                rez = rez * 10 + temp % 10;
                counter++;
                temp = temp / 10;
            }
        } for (int j = 1; j <= counter - 1; j++)
            p = p * 10;
        rez = (rez + (p * prima)) * 10 + ultima;
        cout << rez << " ";
    } return 0;
}
