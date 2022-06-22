#include <bits/stdc++.h>
using namespace std;
int main() {
    int B, S;
    cin >> B >> S;
    cout << S / B << " " << B - (S % B);
    return 0;   
}