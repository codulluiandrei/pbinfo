// ============================
// =  Solutie oficiala Tsin   =
// ============================
// =  Vintila Valentin Ioan   =
// = Caldaruse Marius Catalin =
// ============================
#include <bits/stdc++.h>
#define pi 3.14159265358979323846
using namespace std;
int main()
{
    long double n, r, o;
    cin >> n >> r;
    o = 2 * pi / n;
    cout << fixed << setprecision(12) << (r * sin(o)) / (2 * sin((pi-o) / 2.0) - sin(o));
}