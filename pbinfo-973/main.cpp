#include <iostream>
#include <string.h>
using namespace std;
int main() {
    char s[256];
    cin.getline(s, 256);
    char* p = strtok(s, " ");
    while (p) {
        bool adv = true;
        for (int i = 0; p[i]; i++)
            if (!strchr("aeiou", p[i]))
                adv = false;
        if (adv == true) cout << p << endl;
        p = strtok(NULL, " ");
    } return 0;
}