#include <bits/stdc++.h>
using namespace std;
int main() {
    char voc, con;
    int pozc, pozv, temp = 0;
    char s[11]; cin >> s;
	for (int i = 0; s[i]; i++)
        if (strchr("aeiouAEIOU", s[i])) temp++;
    if (temp == 0 || temp == strlen(s)) cout << "IMPOSIBIL";
    else {
        for (int i = 0; s[i]; i++)
            if (strchr("aeiouAEIOU", s[i])) {   
                voc = s[i];
                pozv = i;
                break;
            }
        for (int i = 0; s[i]; i++)
            if (!strrchr("aeiouAEIOU", s[i])) {
                con = s[i];
                pozc = i;
            }
        s[pozv] = con;
        s[pozc] = voc;
        cout << s;
    } return 0;
}