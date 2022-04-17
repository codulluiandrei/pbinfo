#include <bits/stdc++.h>
using namespace std;

int palindrom(char *editat) {
    char text[21];
    strcpy(text, editat);
    for (int i = 0; text[i]; i++)
        if (text[i] >= 'a')
            text[i] = text[i] - 32;
    for (int i = 0, j = strlen(text) - 1; i < j; i++, j--)
        if (text[i] != text[j])
            return 0;
    return 1;
}

int main() {
    char text[256];
    cin.getline(text, 256);
    char *editat, *palin = NULL, semne[] = " ,.:;";
    editat = strtok(text, semne);
    while (editat) {
        if (palindrom(editat))
            if (!palin) palin = editat;
            else if (strlen(editat) > strlen(palin)) palin = editat;
        editat = strtok(NULL, semne);
    } cout << palin;
    return 0;
}