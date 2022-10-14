#include <bits/stdc++.h>
using namespace std;
char s[200];
bool verif(char c) {
    int k = (int)c;
    if (k == 97 || k == 101 || k == 105 || k == 111 || k == 117)
        return true;
    else return false;
}
char calcul(char c[200]) {
    int s = 0, contor = 0;
    for (int i = 0; i < strlen(c); i++)
        if (c[i] != ' ' && !verif(c[i]) && !isupper(c[i])) {
            s = s + (int)c[i];
            contor++;
        }            
    return (char)(s / (contor));
}
int main() {
    cin.getline(s, 200);
    cout << calcul(s);
}