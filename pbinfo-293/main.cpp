#include <iostream>
using namespace std;
int n, a[101];
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    bool adv = 1;
    for (int i = 1; i <= n; i++) {
        int v[10] = {0};
        int temp = a[i];
        while (temp) v[temp % 10]++, temp = temp / 10;
        for (int k = 0; k < 10; k++)
            if (v[k]>1) adv = 0;
    } if (adv) cout << "DA";
    else cout << "NU";
    return 0;
}