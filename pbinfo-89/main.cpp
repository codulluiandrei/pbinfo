#include <bits/stdc++.h>
using namespace std;

ifstream in("palindrom.in");
ofstream out("palindrom.out");

int palindrom(char * text) {
    for (int i = 0, j = strlen(text) - 1; i < j; i++, j--)
        if (text[i] != text[j])
            return 0;
    return 1;
}

int palindromP(char * text) {
    char temp[250];
    strcpy(temp, text);
    for (int i = 0; temp[i]; )
        if (temp[i] == ' ') {
            char cartemp[250];
            strcpy(cartemp , temp + i + 1);
            strcpy(temp + i, cartemp);
        } else i++;
    return palindrom(temp);
}

int main() {
    int n;
    char textinput[250];
    in >> n;  in.get();
    for (; n ; --n) {
        in.getline(textinput,250);
        out << palindromP(textinput) << endl;
    }
    return 0;
}