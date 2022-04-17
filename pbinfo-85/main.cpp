#include <bits/stdc++.h>
using namespace std;
int main() {
    string text, vocale = "aeiou";
    getline(cin, text);
    bool adv = false;
    for (int i = text.length() - 1; i >= 0; i--)
        if (vocale.find(text[i]) != string::npos ) {
            adv = true;
            text.insert(i + 1 , "*");
        }
    if (adv) cout << text << endl;
    else cout << "FARA VOCALE";
    return 0;
}