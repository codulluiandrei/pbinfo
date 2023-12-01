#include <iostream>
using namespace std;
int main() {
    int T, N, d, solutions = 1;
    cin >> T >> N;
    
    if(T == 1) {
        for(d = 1; d <= N; d++)
            if(N % d == 0)
                cout << d << " ";
    }
    else {
        d = 2;
        while(N != 1) {
            int k = 0;
            while(N % d == 0) {
                N /= d;
                k++;
            }

            solutions *= (2 * k + 1);
            d++;
        }

        cout << solutions / 2 + solutions % 2 << '\n';
    }
}