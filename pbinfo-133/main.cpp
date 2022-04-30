#include <iostream>
#include <string.h>
using namespace std;
int main() {
    char nume[45], prenume[45], temp[45];
    cin >> nume >> prenume;
    for (int i = strlen(prenume) - 1; i >= 0; --i)
        if (strchr("aeiouAEIOU" , prenume[i])) {
            strcpy(temp, prenume + i + 1);
            strcpy(prenume + i, temp);
        }
    strcat(prenume, " ");
    strcat(prenume, nume);
    cout << prenume;
    return 0;
}