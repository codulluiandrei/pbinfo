#include <bits/stdc++.h>
using namespace std;

ifstream in("sortcuv.in");
ofstream out("sortcuv.out");

int main() {
    char text[251], cuv[200][21], *temp;
    int n = 0;
    in.getline(text,251);
    temp = strtok(text, " ");
    while (temp) {
        strcpy(cuv[n++], temp);
        temp = strtok(NULL, " ");
    }
    for (int i = 0; i < n ; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(cuv[i], cuv[j]) > 0){
                char cuvtmp[21];
                strcpy(cuvtmp, cuv[i]);
                strcpy(cuv[i], cuv[j]);
                strcpy(cuv[j], cuvtmp);
            }
    for (int i = 0; i < n; i++) out << cuv[i] << endl;
    return 0;
}