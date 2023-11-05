#include <bits/stdc++.h>
using namespace std;
int vocale(string cuv) {
    int contor = 0;
    for (int i = 0; i < cuv.length(); i++)
        if (cuv[i] == 'a' || cuv[i] == 'e' || cuv[i] == 'i' || cuv[i] == 'o' || cuv[i] == 'u' || cuv[i] == 'A' || cuv[i] == 'E' || cuv[i] == 'I' || cuv[i] == 'O' || cuv[i] == 'U') 
            contor++;
    return contor;
}
int main() {
    char *p, c[256];
    string cuv[256];
    int n = 0;
    cin.getline(c, 256);
    p = strtok(c, " ");
    while(p != NULL) {
       cuv[++n]=p;
       p = strtok(NULL, " ");
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            if (vocale(cuv[i]) < vocale(cuv[j]))
                swap(cuv[i],cuv[j]);
            else if (vocale(cuv[i]) == vocale(cuv[j])) {
                if (cuv[i].length() < cuv[j].length())
                    swap(cuv[i],cuv[j]);
                else if (cuv[i].length() == cuv[j].length()) {
                    for (int k = 0; k < cuv[i].length(); k++)
                        if (cuv[i][k] > cuv[j][k]) {
                            swap(cuv[i], cuv[j]);
                            break;
                        } 
                        else if (cuv[i][k] < cuv[j][k]) 
                            break;
               }
            }
       }
    for (int i = 1; i <= n; i++)
       cout << cuv[i] << "\n";
    return 0;
}