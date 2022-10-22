#include <iostream>
using namespace std;
int n, m, v[1001], maxim = -1, contor = 0;
int main() {
    cin >> m >> n;
    for (int k = 1; k <= m; ++k) {
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int cmaxim = v[0];
        for (int i = 0; i < n; i++)
            if (v[i] > cmaxim)
                cmaxim = v[i];
        if (cmaxim > maxim) {
            maxim = cmaxim;
            contor = 1;        
        } else if (cmaxim == maxim)
            contor++;
    } cout << maxim << " " << contor;
    return 0;
}