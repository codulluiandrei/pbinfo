#include <fstream>
using namespace std;
ifstream in("muzical.in");
ofstream out("muzical.out");
int n, i;
long long int sum;
char a, b, c;
int main() {
    in >> n;
    for (i = 1; i <= n; i++) {
        in >> a >> b;
        if (a == 'd' && b == 'o') {
            in >> c;
            if (c == '1') sum = sum + 0;
            else if (c == '2') sum = sum + 7;
        } if (a == 'r' && b == 'e') sum++;
        if (a == 'm' && b == 'i') sum = sum + 2;
        if (a == 'f' && b == 'a') sum = sum + 3;
        if (a == 's' && b == 'o') {
            in >> c;
            sum = sum + 4;
        } if (a == 'l' && b == 'a') sum = sum + 5;
        if (a == 's' && b == 'i') sum = sum + 6;
    } sum = sum % 8;
    if (sum == 0) out << "do1";
    else if (sum == 1) out << "re";
    if (sum == 2) out << "mi";
    if (sum == 3) out << "fa";
    if (sum == 4) out << "sol";
    if (sum == 5) out << "la";
    if (sum == 6) out << "si";
    if (sum == 7) out << "do2";
    return 0;
}