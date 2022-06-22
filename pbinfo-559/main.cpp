#include <iostream>
using namespace std;
int a, b, c, d, e, S, minim;
int main() {
    cin >> a >> b >> c >> d >> e;
    S = a + b + c + d + e;
    minim = a;
    if (b < minim) minim = b;
    if (c < minim) minim = c;
    if (d < minim) minim = d;
    if (e < minim) minim = e;
    S = S - minim;
    if (a == minim) a = 100001;
    if (b == minim) b =100001;
    if (c == minim) c =100001;
    if (d == minim) d =100001;
    if (e == minim) e =100001;
    minim = a;
    if (b < minim) minim = b;
    if (c < minim) minim = c;
    if (d < minim) minim = d;
    if (e < minim) minim = e;
    S = S - minim;
    cout << S;
    return 0;
}