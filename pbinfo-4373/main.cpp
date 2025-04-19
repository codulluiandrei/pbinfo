#include <iostream>
using namespace std;
long long a, b;
int main(){
    cin >> a >> b;
    long long a1 = a, b1 = b;
    while(b > 0){
        long long r = a % b;
        a = b; b = r;
    }
    long long ni = a1 / a - 1;///note la info
    long long nm = b1 / a - 1; ///note la mate
    cout << ni + nm;
    return 0;
}