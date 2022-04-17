#include <iostream>
#include <string.h>
using namespace std;
int main() {
    char carac[257], voc[] = "aeou";
    cin.getline(carac, 257);
    int i = 0, nr = 0;
    bool adv = true;
    while (carac[i] != '\0') {
        if (strchr(voc, carac[i]))
            adv = false;
        else if (carac[i] != 'i')
            nr++;
        i++;
    } if (adv && nr) cout << "DA";
    else cout << "NU";
    return 0;
}
