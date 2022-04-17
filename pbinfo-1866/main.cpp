#include <fstream>
#include <string.h>
using namespace std;
ifstream in("prosir.in");
ofstream out("prosir.out");
char ch[256];
int main() {
    in.getline(ch, 256);
    int i = 0;
    while (ch[i] != '.') {
        if (((int)ch[i + 1] == 32 || ch[i + 1] == '.') && ch[i] != ' ')  {
            out << 5;
        } else out << ch[i];
        i++;
    } out << '.';
    return 0;
}