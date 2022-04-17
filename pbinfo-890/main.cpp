#include <iostream>
#include <string.h>
using namespace std;
int freq[6];
char carac[256];
int main() {
    cin.getline(carac, 256);
    int i = 0;
    while (carac[i] != '\0') {
        if (carac[i] == 'a' || carac[i] == 'A')
            freq[1]++;
        else if (carac[i] == 'e' || carac[i] == 'E')
            freq[2]++;
        else if (carac[i] == 'i' || carac[i] == 'I')
            freq[3]++;
        else if (carac[i] == 'o' || carac[i] == 'O')
            freq[4]++;
        else if (carac[i] == 'u' || carac[i] == 'U')
            freq[5]++;
        i++;
    } int maxim = 0, rez = 0;
    for (int i = 1; i < 6; ++i)
        if (freq[i] > maxim) {
            maxim = freq[i];
            rez = i;
        }
    char rezolvari[] = "AEIOU";
    cout << rezolvari[rez - 1];
    return 0;
}
