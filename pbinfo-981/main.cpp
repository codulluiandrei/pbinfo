#include <iostream>
using namespace std;
int var = 1, temp, n, viz[1000001], maxim = - 1, nr = 0;
int main() {
    viz[1]=1;
    for (int i = 2; i <= 20; i++) {
        var = var * 2;
        viz[var - 1] = 1;
    } cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        if (viz[temp] == 1) nr++;
        else { if (nr > maxim) 
                maxim = nr; 
            nr = 0;
        }
    } cout << maxim;
    return 0;
}