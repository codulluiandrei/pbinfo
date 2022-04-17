#include <bits/stdc++.h>
using namespace std;
int main() {
    char text[256], editat[256];
    cin.getline(text, 256);
    for (char *temp = text + strlen(text) - 2; temp >= text; temp--)
        if (strchr("aeiou", temp[0]) && strchr("aeiou", temp[1]))
            if (temp > text && strchr("aeiou", temp[-1])) {
                strcpy(editat, temp + 1);
                strcpy(temp, editat);
            } else {
                strcpy(editat, temp + 2);
                strcpy(temp, editat);
            } cout << text;
    return 0;
}