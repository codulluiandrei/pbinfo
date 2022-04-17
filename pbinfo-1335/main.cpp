#include <iostream>
#include <string.h>
using namespace std;
int main() {
    char carac1[257], carac2[257];
    cin >> carac1 >> carac2;
    for (int i = 0; carac1[i] != '\0'; i++)
        if (strchr(carac2, carac1[i])) 
        cout << carac1[i];
    return 0;
}
