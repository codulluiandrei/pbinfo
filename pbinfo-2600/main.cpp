#include <bits/stdc++.h>
using namespace std;
long long nr, temp;
int main() {
    cin >> nr;
    temp = nr * nr + nr * nr * nr * nr;
    cout << (int)(3 * temp / (temp + sqrt(temp)) + sqrt(temp));
    return 0;
}