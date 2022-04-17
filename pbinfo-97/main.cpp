#include <bits/stdc++.h>
using namespace std;
int main() {
    char text1[21], text2[21]; cin >> text1 >> text2;
    int v[26] = {0};
    for (int i = 0; text1[i]; i++) v[text1[i] - 'a']++;
    for (int i = 0; text2[i]; i++) v[text2[i] - 'a']--;
    bool adv = 1;
    for (int i = 0; i < 26; i++)
        if (v[i])
            adv = 0;
    cout << adv;
    return 0;
}