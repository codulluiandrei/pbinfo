#include <fstream>
using namespace std;
ifstream in("hidden_number.in");
ofstream out("hidden_number.out");
int main() {
    int n, contor = 0, S = 0;
    while (in >> n)
        S = S + n, contor++;
    if (S % contor == 0) out << S / contor;
    else out << -1;
    return 0;
}