#include <iostream>
#include <string.h>
using namespace std;
int main() {
    char carac[257], temp[257];
    cin >> carac;
    for (int i = strlen(carac) - 1; i >= 0; --i)
        if (strchr("aeiou", carac[i])) {
            strcpy(temp, carac + i + 1);
            strcpy(carac + i, temp);
        } cout << carac;
    return 0;
}
