#include <bits/stdc++.h>
using namespace std;

ifstream in("palindrom.in");
ofstream out("palindrom.out");

int palindrom(char * s) {
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) if (s[i] != s[j]) return 0;
    return 1;
}

int main() {
    int n; char s[25];
    in >> n ;
    for (int i = 0; i < n; n--) {
        in >> s;
        out << palindrom(s) << endl;
    } return 0;
}