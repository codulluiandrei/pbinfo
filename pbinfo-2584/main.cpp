#include <iostream>
#include <string.h>
using namespace std;
int main() {
    char s[256], temp[50];
    cin.getline(s, 256);
    char* p = strtok(s, " ");
    while (p) {
        cout << p << " ";
        for (int i = 0; i < strlen(p); ++i)
            temp[i] = p[strlen(p) - 1 - i];
        temp[strlen(p)]=0;
        cout << temp << " ";
        p = strtok(NULL, " ");
    }
	return 0;
}