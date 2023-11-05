#include <bits/stdc++.h>
using namespace std;
char s[256], t[256], maxim[256];
int main() {
    cin >> s;
    strcpy(maxim, "");
    for (int i = 0; s[i + 1]; i++)
        for (int j = 2; s[i + j]; j ++) {
            strncpy(t, s + i, j); 
            t[j] = 0;
            if (strstr(s + i + 1, t)) {
                if (strlen(t) > strlen(maxim))
                    strcpy(maxim, t);
                else if (strlen(t) == strlen(maxim))
                    if (strcmp(t, maxim) < 0)
                    strcpy(maxim, t);
            }
    } cout << maxim;
    return 0;
}