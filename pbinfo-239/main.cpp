#include <bits/stdc++.h>
using namespace std;
ifstream in("nrlipsa.in");
ofstream out("nrlipsa.out");
#define cin in
#define cout out
int freq[1001];
int main() {
    int temp, contor = 0;
    while (cin >> temp)
        if (temp < 1000)
            freq[temp] = 1;
    for (int i = 999; i >= 100; i--) {
        if (freq[i] == 0 && contor < 2) {
            cout << i << " ";
            contor++;
        }
    }
    if (contor < 2)
        cout << "NU";
    return 0;
}