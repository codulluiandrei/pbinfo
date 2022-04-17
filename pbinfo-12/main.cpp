#include <bits/stdc++.h>
using namespace std;
int main() {
    char carac[256];
    cin.getline(carac, 256);
    int i = 0;
    while (carac[i]!='\0') {
        if (i == 0 || ((int)carac[i - 1] == 32 || (int)carac[i + 1] == 32) && ((int)carac[i] >= 97 && (int)carac[i] <= 122) || (carac[i + 1] == '\0')) {
            int nr = (int)carac[i] - 32;
            cout << (char)nr;
        } else cout << carac[i];
        i++;
    } return 0;
}