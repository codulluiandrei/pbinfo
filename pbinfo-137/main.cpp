#include <bits/stdc++.h>
using namespace std;
char text[256];
int v[26];
int main() {
    cin.getline(text, 256);
    for (int i = 0; text[i]; i++)
        if (text[i] >= 'a' && text[i] <= 'z')
            if (v[text[i] - 'a'] == 0)
                cout << text[i] << " ", v[text[i] - 'a'] = 1;
    return 0;
}