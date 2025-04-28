#include <iostream>
using namespace std;
short n;
int main () {
    cin>>n;
    n &= (-1 << 2);
    cout<<n;
    return 0;
}