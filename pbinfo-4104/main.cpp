#include <iostream>
using namespace std;
int main() {
    int a, b, x[10001], y[10001], minim = 1000000001;
    bool exista = false;
    cin >> a;
    for (int i = 1; i <= a; i++)
        cin >> x[i];
    cin >> b;
    for (int i = 1; i <= b; i++) {
        cin >> y[i];
    	if (y[i] < minim)
            minim = y[i];
    }
    for (int i = 1; i <= a; i++) {
        bool adv = true;
            if (x[i] > minim)
                adv = false;
		if (adv == true) {
            exista = true;
            cout << x[i] << " ";
        }
    }
    if (!exista)
        cout << "NU EXISTA";
    return 0;
}
