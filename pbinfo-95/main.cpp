#include <bits/stdc++.h>
using namespace std;
int main() {
    string text; getline(cin, text);
    int perechi = 0;
    for (int i = 1; text[i]; i++)
        if (string("aeiou").find(text[i]) != string :: npos && string("aeiou").find(text[i - 1]) != string :: npos)
            perechi++;
    cout << perechi;
    return 0;
}