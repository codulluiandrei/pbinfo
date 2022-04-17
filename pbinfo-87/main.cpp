#include <bits/stdc++.h>
using namespace std;

ifstream in("lgmax.in");
ofstream out("lgmax.out");

int main() {
    int n; char text[256], temp[256];
    in >> n; in.getline(temp, 256);
    for (int i = 0; i < n ; n--){
        in.getline(text, 256);
        if (strlen(text) > strlen(temp)) strcpy(temp, text);
    } out << temp << endl;
    return 0;
}