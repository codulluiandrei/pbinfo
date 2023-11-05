#include <iostream>
#include <string.h>
using namespace std;
int main() {
    char s[256];
    bool adv = false;
    cin.getline(s, 256);
    char* p = strtok(s, " ");
    while (p) {
        // DO, RE, MI, FA, SOL, LA, SI
        if (strstr(p, "DO") || strstr(p, "RE") || strstr(p, "MI") || strstr(p, "FA") || strstr(p, "SOL") || strstr(p, "LA") || strstr(p, "SI")) {
            adv = true;    
            cout << p << "\n";
        }
        p = strtok(NULL, " ");
    } 
    if (adv == false)
        cout << "nu exista";
    return 0;
}