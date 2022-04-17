#include <iostream>
#include <string.h>
using namespace std;
int main() {
    char carac[257];
    cin.getline(carac, 257);
    int i = 1;
    if ((int) carac[0] >= 65 && (int) carac[0] <= 90)
        cout << carac[0];
    while (carac[i] != '\0') {
        if (carac[i - 1] == ' ' && (int) carac[i] >= 65 && (int) carac[i] <= 90)
            cout << carac[i];
        i++;
    } return 0;
}
