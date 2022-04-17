#include <iostream>
#include <string.h>
using namespace std;
bool palindrom(char* p) {
    for (int i = 0, j = strlen(p) - 1; i < j; i++, j--)
        if (p[i] != p[j]) return false;
    return true;
} int main() {
    char s[256], cmin[11];
    cin.getline(s, 256);
    char * p = strtok(s, " .,");
    int temp = 0;
    while (p) {
        if (palindrom(p) == true) {
            temp++;
            if (temp == 1) strcpy(cmin, p);
            else if (strcmp(p, cmin) < 0) strcpy(cmin, p);
        } p = strtok(NULL , " .,");
    } if (temp > 0) cout << cmin;
    else cout << "IMPOSIBIL";
    return 0;
}