#include <iostream>
#include <string.h>
using namespace std;
char s[256], voc[]="aeiou";
int main() {
    cin.getline(s, 256);
    char t[256];
    for (int i = 0; s[i]; i++)
        if (strchr(voc, s[i])) {
            strcpy(t, s + i);
            s[i + 1] = 'p';
            strcpy(s + i + 2, t);
            i = i + 2;
        } cout << s;
    return 0;
}