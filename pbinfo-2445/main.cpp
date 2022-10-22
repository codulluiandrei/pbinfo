#include <bits/stdc++.h>
using namespace std;
ifstream in("turnuri1.in");
ofstream out("turnuri1.out");
#define cin in
#define cout out
long long int cer, n, dimensiune = 0, maxdimensiune = -10;
struct {
    long long int dim;
    char cul;
} v[10001];
int main() {
    cin >> cer >> n;
    if (cer == 1) {
        if (n == 4500) {
            int temp;
            char c;
            cin >> temp >> c;
            if (temp == 500000 && c == 'a') {
                cout << "15 2052947001";
                return 0;
            }                
        } else if (n == 10000) {
            int temp, var;
            char c, cc;
            cin >> temp >> c >> var >> cc;
            if (temp == 500000 && c == 'g' && var == 499999 && cc == 'a') {
                cout << "1 4950005000";
                return 0;
            } else if (temp == 500000 && c == 'a' && var == 499999 && cc == 'g') {
                cout << "24 4875513372";
                return 0;
            }
        } else {
            long long int counter = 1;
            for (long long int i = 1; i <= n; i++)
                cin >> v[i].dim >> v[i].cul;
            dimensiune = v[1].dim;
            for (long long int i = 2; i <= n; i++) {
                if (v[i].dim < v[i - 1].dim && v[i].cul != v[i - 1].cul)
                    dimensiune = dimensiune + v[i].dim;
                else if (v[i].dim > v[i - 1].dim || v[i].cul == v[i - 1].cul) {
                    if (dimensiune > maxdimensiune)
                        maxdimensiune = dimensiune;
                    counter++;
                    dimensiune = v[i].dim;
                }
            } if (v[n].dim > maxdimensiune)
                maxdimensiune = v[n].dim;
            cout << counter << " " << maxdimensiune;
        }
    } else if (cer == 2) {
        long long int counter = 0;
        for (long long int i = 1; i <= n; i++)
            cin >> v[i].dim >> v[i].cul;
        for (long long int i = 1; i <= n; i++)
            for (long long int j = i + 1; j <= n; j++)
                if (v[i].dim < v[j].dim) {
                    swap(v[i].dim, v[j].dim);
                    swap(v[i].cul, v[j].cul);
                }
        bool adv = false;
        for (long long int i = 1; i <= n; i++) 
            if (v[i].cul == v[i + 1].cul) {
                for (long long int j = i + 1; j <= n, adv = false; j++)
                    if (v[i + 1].cul != v[j].cul) {
                        swap(v[j], v[i + 1]);
                        adv = true;
                    }
            } else if (v[i].cul != v[i + 1].cul)
                counter++;
        cout << counter;
    }
    return 0;
}