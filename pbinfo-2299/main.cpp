#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main() {
    int n, temp; cin >> n;
    long long int prod = 1;
    for (int i = 1 ; i <= n ; i++) {
        cin >> temp;
        prod = prod * temp;    
    } double mg = (double)1 / n;
    cout << fixed << setprecision(2) << pow(prod, mg);
    return 0;    
}