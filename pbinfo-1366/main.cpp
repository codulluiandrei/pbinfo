#include <iostream>
using namespace std;
int main() {
    int n, i, v[3000], j;
    bool adv;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> v[i];
    do { for (i = 1; i <= n; i++)
            cout << v[i] << " ";
        cout << endl;
        adv = false; i = 2;
        while (i <= n)
            if ((v[i - 1] + v[i]) % 2 == 0 && v[i - 1] != v[i]) {
                for (j = n; j >= i; j--)
                    v[j + 1] = v[j];
                v[i] = (v[i - 1]+ v[i + 1]) / 2;
                n++;
                i = i + 2;
                adv = true;
            } else i++;
    } while (adv == true);
    return 0;
}
