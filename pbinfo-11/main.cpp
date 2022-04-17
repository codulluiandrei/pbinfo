#include <bits/stdc++.h>
using namespace std;
int main() {
    char carac[21]; cin >> carac;
    int i = 0;
    while (carac[i] != '\0') {
        if (carac[i] == 'a') cout << 'A';
        else if (carac[i] == 'e') cout << 'E';
        else if (carac[i] == 'i') cout << 'I';
        else if (carac[i] == 'o') cout << 'O';
        else if (carac[i] == 'u') cout << 'U';
        else cout << carac[i];
        i++;
    } return 0;
}