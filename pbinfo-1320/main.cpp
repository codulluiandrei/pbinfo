#include <iostream>
using namespace std;
int main() {
    int n, v[1001];
    bool cr, eg, de;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    cr = eg = de = false;
    for (int i = 0; i < n - 1; i++)
        if (v[i] == v[i + 1]) eg = true;
        else if (v[i] < v[i + 1]) cr = true;
        else de = true;
        if (cr && de)
            cout << "sir neordonat";
        else if (eg && !cr && !de)
            cout << "sir constant";
        else if (cr && !eg && !de)
            cout << "sir strict crescator";
        else if (cr && eg && !de)
            cout << "sir crescator";
        else if (de && eg && !cr)
            cout << "sir descrescator";
        else cout << "sir strict descrescator";
	return 0;
}