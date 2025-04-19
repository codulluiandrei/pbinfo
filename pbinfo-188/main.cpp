#include <bits/stdc++.h>
using namespace std;
ifstream in("inlocuirecuvant.in");
ofstream out("inlocuirecuvant.out");
int main(){
    char a[20], b[20], t[500], *temp;
    in >> a >> b;
    in.getline(t, 500);
    in.getline(t, 500);
    temp = strstr(t, a);
    while (temp) {
        if ((temp == t || *(temp - 1) == ' ') && (*(temp + strlen(a)) < 'a' || *(temp + strlen(a)) > 'z')) {
            char t[500];
            strcpy(t, temp + strlen(a));
            strcpy(temp, b);
            strcpy(temp + strlen(b), t);
            temp = strstr(temp + strlen(b), a);
        } else temp = strstr(temp + strlen(a), a);
    } out << t << endl;
    return 0;
}