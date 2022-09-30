#include <bits/stdc++.h>
using namespace std;
ifstream in("joc3.in");
ofstream out("joc3.out");
#define cin in
#define cout out
long long int n, x, y;
long long int t = 0, s = 0, b = 1, r = 1;
int freq[30003];
int main() {
    cin >> n >> x >> y;
    freq[1] = 11;
    t = n - 1;
    do {
        s++;
        b = b + x;
        r = r - y;
        if (r < 1)
            r = r + n;
        if (b > n)
            b = b - n;
        if (freq[b] == 0)
            t--;
        if ((freq[r] == 0) && (b != r))
            t--;
        freq[b]++;
        freq[r] = freq[r] + 10;
    } while ((b != r) && (freq[r] / 10 != 2) && (freq[b] % 10 != 2));
    cout << t << " " << s << " " << b << " " << r;
    return 0;
}