#include <iostream>
using namespace std;
int main() {
    int n, a[1001], b[1001];
    cin  >> n; 
    for (int i = 0 ; i < n ; ++ i)
        cin >> a[i];
    for (int i = 0 ; i < n ; ++ i)
        cin >> b[i];
    bool adv = true;
    for (int i = 0; i < n && adv; i++) {
        int  p = -1;
        for (int  j = 0; j < n && p == -1; ++j)
            if (a[i] == b[j])
                p = j;
        if (p > -1) b[p] = -1;
        else adv = false;
    } if (adv) cout << "DA";
    else cout << "NU";
    return 0;
}