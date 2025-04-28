/// Solutie - Moca Andrei - 60p
#include <bits/stdc++.h>
using namespace std;
string s;
int q, op;
char c;
int main() {
    cin >> s >> q;
    while (q--) {
        cin >> op;
        if (op == 1)
            cin >> c, s = c + s;
        else if (op == 2)
            cin >> c, s = s + c;
        else if (op == 3)
            s.erase(s.begin());
        else if (op == 4)
            s.erase(s.begin() + s.size() - 1);
        else reverse(s.begin(), s.end());
    }
    cout << s;
    return 0;
}