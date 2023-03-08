#include <bits/stdc++.h>
using namespace std;
int freq[15];
int main() {
    int n;
    bool adv = true;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        while (temp) {
            freq[temp % 10]++;
            temp = temp / 10;
        }
    }
    while (adv == true) {
        adv = false;
        int contor = 0, minim = 100000, poz = 0;
        for (int i = 0; i <= 9; i++)
            if (freq[i] > 0)
                adv = true, contor++;
        if (contor == 1)
            adv = false;
        for (int i = 0; i <= 9; i++)
            if (freq[i] < minim && freq[i] > 0)
                poz = i, minim = freq[i];
        freq[poz] = 0;
        cout << poz << " ";
    }
}
