#include <iostream>
using namespace std;
int main() {
    int v[1001], n;
    bool cr, de;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    cr = de = false;
    for (int i = 0; i < n - 1; i++)
        if (v[i] == v[i + 1]) {
            cout << "NU";
            return 0;
        } else if (v[i] > v[i + 1])
                if (cr == true) de = true;
                else {
                    cout << "NU";
        			return 0;
                } else if (v[i] < v[i + 1])
                    if (!de) cr = true;
        			else {
                        cout << "NU";
        				return 0;
                    } if (cr && de) cout << "DA";
    				else cout << "NU";
    return 0;
}