#include <fstream>
#include <string.h>
using namespace std;
ifstream in("calcul3.in");
ofstream out("calcul3.out");
int main() {
    int var, temp;
    char carac;
    in >> var;
    out << var;
    while (in >> carac) {
        if (carac != '=') {
            in >> temp;
            out << carac << temp;
            if (carac == '+')
                var = var + temp;
            else 
                var = var - temp;
        }
    } out << "=" << var;
    return 0;
}