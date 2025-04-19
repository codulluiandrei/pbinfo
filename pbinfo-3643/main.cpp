#include <iostream>
using namespace std;
long long c, v, s, grup, i;
int main () {
    cin>>c>>v;
    if (c == 1) {
        /// aflam valoarea de pe pozitia v
        s = 0;
        for (grup = 1;;grup++) {
            s += grup + (grup+1)/2;
            if (s >= v)
                break;
        }
        s -= (grup + (grup+1)/2);
        v -= s;
        /// ne intereseaza valoarea de pe pozitia v din grupul
        /// grup
        if (v <= grup) {
            cout<<v<<"\n";
        } else {
            v -= grup;
            cout<<2*v-1<<"\n";
        }
    } else { /// c = 2
        for (i=1;i<=v-1;i++) {
            s += i + (i+1)/2;
        }
        cout<<s+v<<"\n";
    }
    return 0;
}