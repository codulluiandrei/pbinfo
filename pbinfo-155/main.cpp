#include <bits/stdc++.h>
using namespace std;
int freq[11], contor = 0, maxim = 0;
char carac[300];
int main() {
    cin.getline(carac, 300);
    while (carac[contor] != '') {
        if (carac[contor] == '0') freq[0]++;
        if (carac[contor] == '1') freq[1]++;
        if (carac[contor] == '2') freq[2]++;
        if (carac[contor] == '3') freq[3]++;
        if (carac[contor] == '4') freq[4]++;
        if (carac[contor] == '5') freq[5]++;
        if (carac[contor] == '6') freq[6]++;
        if (carac[contor] == '7') freq[7]++;
        if (carac[contor] == '8') freq[8]++;
        if (carac[contor] == '9') freq[9]++;
        contor++;
    } int rez = -1;
    for (int i = 0; i <= 10; ++i)
        if (freq[i] > maxim)
            maxim = freq[i], rez = i;
    if (rez == -1) cout << "NU";
    else cout << rez;
    return 0;
}