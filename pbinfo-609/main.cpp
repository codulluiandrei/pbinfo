#include <bits/stdc++.h>
using namespace std;
int main() {
    char sir[201], temp[201];
    cin.getline(sir, 201);
    for (int i = strlen(sir) - 1; i >= 0; i--)
        if (strchr("aeiou", sir[i]) != NULL) {
            strcpy(temp, sir + i);
            strcpy(sir + i + 1, temp);
        } cout << sir;
    return 0;
}