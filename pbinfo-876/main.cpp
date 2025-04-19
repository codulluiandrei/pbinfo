#include <bits/stdc++.h>
using namespace std;
int n;
queue<int> coada;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string com;
        int nr;
        cin >> com;
        if (com == "push")
            cin >> nr, coada.push(nr);
        else if (com == "pop")
            coada.pop();
        else if (com == "front")
            cout << coada.front() << "\n";
    }
    return 0;
}