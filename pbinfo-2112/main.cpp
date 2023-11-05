#include <fstream>
using namespace std;
ifstream in("tablita.in");
ofstream out("tablita.out");
#define cin in
#define cout out
int main() {
    int n, contor = 1, S = 0;
    cin >> n;
    while (S + contor < n)
        S = S + contor, contor++;
    cout << contor;
    return 0;
}