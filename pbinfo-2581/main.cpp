#include <iostream>
using namespace std;
long long n, k;
int main () {
    cin>>n>>k;
    n |= (1LL<<k);
    cout<<n;
    return 0;
}