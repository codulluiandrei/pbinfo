#include <iostream>
#include <string.h>
using namespace std;
char s[111], t[111], *p;
bool exist = false;
int main() {
    cin.getline(s, 101);
    p = strtok(s, " ");
    while (p != NULL) {
        bool adv = true;
        for (int i = 0; p[i] != ''; i ++)
            if (strchr("0123456789", p[i]) == NULL)
                adv = false;
        if (adv == true) {
            if (exist == false) strcpy(t, p), exist = true;
            else if (p[0] > t[0]) strcpy(t, p);
        } p = strtok(NULL, " ");
    } if (exist == true) cout << t;
    else cout << "nu exista";
    return 0;
}