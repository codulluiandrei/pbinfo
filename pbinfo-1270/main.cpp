#include <bits/stdc++.h>
using namespace std;
long long int nr, val;
char s[100];
int main() {
    cin >> s;
    for (char i = 0; i < strlen(s); i++) {
        if ((s[i] >= '0') && (s[i] <= '9')) 
            val = s[i] - '0';
        if ((s[i] >= 'A') && (s[i] <= 'F'))
            val = 10 + s[i]-'A';
        nr = nr * 16 + val;
    } cout << nr;
    return 0;
}