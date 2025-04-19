#include <iostream>
using namespace std;
long long n, t, p, i, suma, s, x, a;
int main () {
    cin>>n>>t>>p;
    cin>>a;
    suma = a;
    for (i=2;i<=n;i++) {
        cin>>x;
        suma += x;
        if (i <= p) {
            if (t == 1 && x < a)
                a = x;
            if (t == 2 && x > a)
                a = x;
        }
    }
    s = 0;
    if (t == 1) {
        while (a!=0) {
            s += a%10;
            a /= 10;
        }
    } else {
        for (i=1;i<=a/i;i++)
            if (a%i == 0) {
                s++;
                if (i!=a/i)
                    s++;
            }
    }
    cout<<s<<"\n"<<suma;
    return 0;
}