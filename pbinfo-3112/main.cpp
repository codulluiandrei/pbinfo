#include <iostream>
#include <string.h>
using namespace std;
char s[111], *p;
int n;
bool exist = false;
int main() {
    cin.getline(s, 101);
    cin >> n;
    p = strtok(s, " ");
    while (p != 0) {
        if (strlen(p) == n) {
            cout << p << "\n";
            exist = true;
        } p = strtok(NULL, " ");
    } if (exist == false) cout << "nu exista" << endl;
    return 0;
}