#include <bits/stdc++.h>
using namespace std;
ifstream in("palindrom3.in");
ofstream out("palindrom3.out");
#define cin in
#define cout out
int freq[11], n, nrimp = 0;
int main() {
    cin >> n;
    if (n < 10) 
        cout << n;
    else if (n > 9) {
        while (n > 0) {
            freq[n % 10]++;
            n = n / 10;
        } bool adv = true;
        for (int i = 0; i <= 9; i++)
            if (freq[i] % 2 == 1)
                nrimp++;
        if (nrimp > 1)
            adv = false;
        if (adv) { bool pare = false;
            for (int i = 1; i <= 9; i++)
                if (freq[i] && freq[i] % 2 == 0)
                    pare = true;
            int imp = -1;
            for (int i = 0; i <= 9; i++)
                if (freq[i] % 2 == 1)
                    imp = i;
            if (freq[imp] == 1 && imp >= 0 && pare == 0 && freq[0] % 2 == 0)
                cout << "-1";
            else {
                for (int i = 9; i >= 0; i--) 
                    for (int j = 1; j <= freq[i] / 2; j++)
                        cout << i;
                if (imp >= 0)
                    cout << imp;
                for (int i = 0; i <= 9; i++)
                    for (int j = 1; j <= freq[i] / 2; j++)
                        cout << i;
            }
        } else
            cout << "-1";
    } return 0;
}