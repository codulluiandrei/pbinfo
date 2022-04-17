#include <bits/stdc++.h>
using namespace std;
int main() {  
    int n, n2, v1[25001], v2[200001], inceput, sfarsit, mijloc;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v1[i];
    cin >> n2;
    for (int i = 1; i <= n2; i++) cin >> v2[i];
    for (int i = 1; i <= n2; i++) {
         inceput = 1;
         sfarsit = n;
        while (inceput <= sfarsit) {
            mijloc = (inceput + sfarsit) / 2;
            if (v1[mijloc] == v2[i]) {
                cout << 1 << " ";
                break;
            } else {
                if (v1[mijloc] < v2[i]) inceput = mijloc + 1;
                else sfarsit = mijloc - 1;
            }
        } if (inceput > sfarsit) cout << 0 << " ";
    } return 0;
}   