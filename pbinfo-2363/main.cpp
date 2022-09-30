#include <bits/stdc++.h>
using namespace std;
ifstream in("joc8.in");
ofstream out("joc8.out");
#define cin in
#define cout out
int n;
bool alternant(char v[]) {
    for (int i = 1; i < strlen(v) - 1; i++) {
        if (v[i - 1] < v[i] && v[i] < v[i + 1])
            return false;
        else if (v[i - 1] > v[i] && v[i] > v[i + 1])
            return false;
        else if (v[i - 1] == v[i])
            return false;
        else if (v[i] == v[i + 1])
            return false;
        // a = i - 1; b = i; c = i + 1
        // a < b < c, a > b > c, a == b, b == c
    } return true;
}
int main() {
    cin >> n;
    int s = 0;
    for (int i = 1; i <= n; i++) {
        char v[11];
        cin >> v;

        if (strlen(v) == 1)
            s++;
        if (strlen(v) % 2 != 0 && strlen(v) > 2)
            if (alternant(v))
                s++;
    } cout << s;
    return 0;
}