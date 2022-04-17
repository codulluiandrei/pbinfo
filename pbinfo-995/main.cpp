#include <fstream>
using namespace std;
ifstream in("numere6.in");
ofstream out("numere6.out");
int v[10], n, m;
int main() {
    in  >> n >> m;
    do {
        v[n % 10]++;
        n = n / 10;
    } while (n != 0);
    do {
        v[m % 10]++;
        m = m / 10;
    } while (m != 0);
    for (int i = 9; i >= 0; i--)
        for (int j = 1; j <= v[i]; j++)
            out << i;
    return 0;
}
