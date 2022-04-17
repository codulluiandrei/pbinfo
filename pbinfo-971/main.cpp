#include <iostream>
#include <math.h>
using namespace std;
int main() { 
    int n, temp, C = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) { 
        cin >> temp; float f = sqrt(temp);
        if (f * f == temp) C = C + 3 * temp;
        else for (int d = 2 ; d * d <= temp; d++)
            if (temp % d == 0) {
            	C = C + temp;
            	break;
        } } cout << C;
    return 0;
}