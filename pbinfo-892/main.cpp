#include <iostream>
#include <string.h>
using namespace std;
char s[256], vocale[] = "aeiou";
int main() {
    cin.getline(s, 256);
    char t[256];
    for (int i = 0; s[i]; i++)
        if (strchr(vocale, s[i])) {
            strcpy(t, s + i + 2);
            strcpy(s + i, t);
        }
    cout << s;
    return 0;
}