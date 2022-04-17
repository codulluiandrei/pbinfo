#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int ciur[1000001] = {0};
    ciur[0] = ciur[1] = 1;
    for (int i = 4; i <= n; i = i + 2)
        ciur[i] = 1;
    for (int i = 3; i * i <= n; i = i + 2) 
        if (ciur[i] == 0)
            for (int j = i * i; j <= n; j = j + 2 * i)
                ciur[j] = 1;
    for (int i = 1; i <= n; ++i)
        if (ciur[i] == 0) cout << i << " ";
    return 0;
}