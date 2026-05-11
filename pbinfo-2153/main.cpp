// Autor: Mihai Enache
#include <iostream>
#include <fstream>
using namespace std;
const int MAX_N = 1000002;
int C, N, K;
int v[MAX_N];
int main() {
    ifstream cin("mirror.in");
    ofstream cout("mirror.out");
    cin >> C >> N >> K;
    for(int i = 1; i <= N; ++i) {
        cin >> v[i];
    }
    if(C == 1) {
        int currentValue = 0;
        int nrBits = 0;
        for(int i = 1; i <= N; ++i) {
            int maxBit = 0;
            for(int bit = 31; bit >= 0; --bit) {
                if(v[i] & (1 << bit)) {
                    maxBit = bit;
                    break;
                }
            }
            for(int bit = maxBit; bit >= 0; --bit) {
                if(v[i] & (1 << bit)) {
                    currentValue = currentValue * 2 + 1;
                }
                else {
                    currentValue = currentValue * 2;
                }
                ++nrBits;
                if(nrBits == K) {
                    cout << currentValue << " ";
                    currentValue = 0;
                    nrBits = 0;
                }
            }
        }
		cout << "\n";
    }
    else {
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= K; ++j) {
                if(!v[i]) {
                    break;
                }
                int maxBit = 0;
                for(int bit = 31; bit >= 0; --bit) {
                    if(v[i] & (1 << bit)) {
                        maxBit = bit;
                        break;
                    }
                }
                v[i] ^= (1 << (maxBit + 1)) - 1;
            }
        }
        int startPos = -1;
        int endPos = -1;
        int maxLength = 0;
        for(int bit = 0; bit < 32; ++bit) {
            int currentLength = 0;
            for(int i = 1; i <= N; ++i) {
                if(v[i] & (1 << bit)) {
                    ++currentLength;
                }
                else {
                    currentLength = 0;
                }
                if(currentLength > maxLength || (currentLength == maxLength && i - currentLength + 1 < startPos)) {
                    maxLength = currentLength;
                    startPos = i - currentLength + 1;
                    endPos = i;
                }
            }
        }
        cout << maxLength << "\n";
        cout << startPos << " " << endPos << "\n";
    }
    return 0;
}