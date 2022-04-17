#include <iostream>
using namespace std;
int freq[1000005], n, temp, stanga, dreapta, cond;
int main() {  
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        if (freq[temp] && i - freq[temp] + 1 > cond) {
            cond = i - freq[temp] + 1;
            stanga = freq[temp];
            dreapta = i;
        } if (!freq[temp]) freq[temp] = i;
    } cout << stanga << " " << dreapta;
    return 0;
}