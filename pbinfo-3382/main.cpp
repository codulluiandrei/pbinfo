#include <bits/stdc++.h>
using namespace std;
ifstream in("robot.in");
ofstream out("robot.out");
#define cin in
#define cout out
int cer, n, freq[10010];
int main() {
    cin >> cer >> n;
    for (int i = 1; i <= n; i++) {
        int lg1, lg2;
        cin >> lg1 >> lg2;
        if (lg1 > lg2) {
            int temp = lg1;
            lg1 = lg2;
            lg2 = temp;
        } freq[lg1 * 100 + lg2]++;
    }
    if (cer == 1) {
        int contor = 0;
        for (int i = 100; i <= 10001; i++)
            if (freq[i] != 0)
                contor++;
        cout << contor;
    } else if (cer == 2) {
        int minim = 100000001;
        for (int i = 1; i <= 10001; i++)
            if (freq[i] != 0 && freq[i] < minim)
                minim = freq[i];
        cout << minim;
    }
    return 0;
}