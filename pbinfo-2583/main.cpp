#include <iostream>
using namespace std;
int n;
int main () {
    cin>>n;
    n -= (n & -n);
    cout<<n;
    return 0;
}