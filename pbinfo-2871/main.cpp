#include <bits/stdc++.h>
using namespace std;
ifstream in("fulger.in");
ofstream out("fulger.out");
#define cin in
#define cout out
long long int n, contor = 0;
long long int cod(long long int n) {
    long long int copie = n, nr = 0;
    while (copie > 0) {
        nr = nr * 10 + 9;
        copie = copie / 10;
    } return nr - n;
}
bool verif(long long int n) {
    if (n % 100 == 10)
        return true;
    return false;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        long long int temp;
        cin >> temp;
        cout << cod(temp) << " ";
        if (verif(cod(temp)) == true) 
            contor++;
    } cout << "\n" << contor;
    return 0;
}