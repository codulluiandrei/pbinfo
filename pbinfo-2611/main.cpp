#include <iostream>
using namespace std;
long long a, b, m;
long long cmmdc(long long a, long long b) {
    while (b) {
        long long r = a%b;
        a = b;
        b = r;
    }
    return a;
}
int main () {
    cin>>a>>b;
    m = a/cmmdc(a, b) * b;
    cout<<(m/a-1) + (m/b-1);
    return 0;
}