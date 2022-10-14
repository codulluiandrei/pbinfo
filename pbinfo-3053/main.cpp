#include <bits/stdc++.h>
using namespace std;
ifstream in("evenoddxxl.in");
ofstream out("evenoddxxl.out");
#define cin in
#define cout out
int main() {
    string s;
    cin >> s;
    if ((s.back() - '0') % 2 == 0)
        cout << "Par";
    else
        cout << "Impar";
}