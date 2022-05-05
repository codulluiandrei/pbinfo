#include <iostream>
#include <string.h>
using namespace std;
int apcar(char * s, char c) {
    int contor = 0;
    for (int i = 0 ; s[i] ; i++)
        if (s[i] == c)
            contor++;
    return contor;
}
int main() {
    char s[256], v[] = "aeiouAEIOU";
    int contor = 0;
    cin.getline(s, 256);
    for (int i = 0 ; v[i] ; i ++)
        contor = contor + apcar(s, v[i]);
    cout << contor;
    return 0;
}