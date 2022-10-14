#include <bits/stdc++.h>
using namespace std;
char carac[256];
int main() {
    cin.getline(carac, 256);
    char lit = 0;
    int nrap = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        int contor = 0;
        for (int i = 0; carac[i]; ++i)
            if (carac[i] == c)
                contor++;
        if (contor > nrap) {
            nrap = contor;
            lit = c;   
        }
    } cout << lit;
    return 0;
}