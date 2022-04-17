#include <bits/stdc++.h>
using namespace std;

ifstream in("vocmax.in");
ofstream out("vocmax.out");

int nrvocale(string text) {
    int rezultat = 0;
    for (int i = 0; text[i]; i++)
        if (string("aeiou").find(text[i]) != string::npos)
            rezultat++;
    return rezultat;
}

int main() {
    int n;
    string text, temp;
    in >> n; 
    in.get(); getline(in, temp);
    for (n--; n; --n) {
        getline(in, text);
        if (nrvocale(text) > nrvocale(temp))
            temp = text;
    } out << temp << endl;
    return 0;
}