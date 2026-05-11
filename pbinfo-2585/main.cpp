#include <iostream>
using namespace std;
int n, k;
int main () {
    cin>>n>>k;
    cout<<(n&((1LL<<k)-1));
    return 0;
}