#include <fstream>
#include <string.h>
using namespace std;
ifstream in("doarvocale.in");
ofstream out("doarvocale.out");
int main() {
    char carac[256], voc[] = "aeiou";
    int n, rez = 0;
    in >> n;
    for (int t = 1; t <= n; ++t) {
        in >> carac;
        bool adv = true;
        for (int i = 1; i <= strlen(carac); ++i)
            if (!strchr(voc, carac[i])) adv = false;
        if (adv == true) rez++;
    } out << rez;
    return 0;
}
