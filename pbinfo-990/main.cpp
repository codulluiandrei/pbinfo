#include <fstream>
#include <string.h>
using namespace std;
ifstream in("sortarecuvinte1.in");
ofstream out("sortarecuvinte1.out");
int main() {
    char mat[210][35];
    int n = 0;
    while (in >> mat[n++]);
    n--;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (strcmp(mat[i], mat[j]) > 0) {
                char txt[31];
                strcpy(txt, mat[i]);
                strcpy(mat[i], mat[j]);
                strcpy(mat[j], txt);
            }
    for (int i = 0; i < n; ++i)
        out << mat[i] << "\n";
    return 0;
}