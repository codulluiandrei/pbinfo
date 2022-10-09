#include <iostream>
using namespace std;
int main() {
    int n, v[1005];
    cin  >> n;  
    for (int i = 0 ; i < n ; ++ i)
        cin >> v[i];
    int a = v[0], b = v[n-1];
    if (a > b) {
        a = v[n - 1];    
        b = v[0];
    } bool adv = true;
    for (int i = 0; i < n; i++ )
        if (v[i] < a || v[i] > b) adv = false;
    if (adv) cout << "DA";
    else cout << "NU";
    return 0;
}