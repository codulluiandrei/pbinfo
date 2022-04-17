#include <bits/stdc++.h>
using namespace std;
int main() {
    char text[101]; cin >> text;
    for (char *temp = text; *temp; temp++) {
        char cuv = *temp;
        temp[0] = 0;
        cout << text << temp + 1 << endl;
        temp[0] = cuv;
    } return 0;
}