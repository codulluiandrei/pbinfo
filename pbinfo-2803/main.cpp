#include <bits/stdc++.h>
using namespace std;
int p;
string s, temp;
int main() {
    cin >> p;
    cin.get();
    getline(cin, s);
    for (int i = 0; i <= s.size() - p; i++) {
        temp = s;
        temp.erase(i, p);
        cout << temp << "\n";
    }
    return 0;
}