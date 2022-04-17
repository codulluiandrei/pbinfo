#include <bits/stdc++.h>
using namespace std;

ifstream in("cuvmax.in");
ofstream out("cuvmax.out");

int nrcuvinte(char * text) {
    int cuvinte = 0;
    if (text[0] != ' ') cuvinte++;
    for (int i = 1; text[i]; i++)
        if (text[i] != ' ' && text[i - 1] == ' ')
            cuvinte++;
    return cuvinte;
}

int main() {
    int n; char text[256], temp[256];
    in >> n; in.getline(temp, 256);
    for (int i = 1; i <= n; --n) {
        in.getline(text, 251);
        if (nrcuvinte(text) > nrcuvinte(temp))
            strcpy(temp, text);
    } out << temp << endl;
    return 0;
}