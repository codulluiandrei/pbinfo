#include <iostream>
using namespace std;
long long n, k, t;
int main () {
    cin>>t;
    for (;t--;) {
        cin>>n>>k;
        cout<<((n>>k) & 1LL);
    }
    return 0;
}