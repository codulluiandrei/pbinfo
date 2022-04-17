#include <bits/stdc++.h>
using namespace std;
int main() {
    float d1, d2, l;
    cin >> d1 >> d2;
    l = sqrt(d1 * d1 + d2 * d2) / 2;
    cout<< 4 * l << " "<< d1 * d2 / 2 << endl;
    return 0; 
}