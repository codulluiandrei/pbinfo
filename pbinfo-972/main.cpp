#include <iostream>
#include <string.h>
using namespace std;
char carac[300];
char voc[] = "aeiou", cons[] = "bcdfghjklmnpqrstvwxyz";
int rez = 0;
int main() {
    cin.get(carac, 300);
    for (int i = 1; i < strlen(carac) - 1; ++i)
        if (strchr(voc, carac[i]) &&strchr(cons, carac[i - 1]) && strchr(cons, carac[i + 1]))
            rez++;
    cout << rez;
    return 0;
}
