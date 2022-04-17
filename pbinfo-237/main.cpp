#include <fstream>
using namespace std;

ifstream in("sume.in");
ofstream out("sume.out");

int main() {
    int n, v[101], temp1 = 0, temp2 = 0;
    in >> n;
    for (int i = 1; i <= n; i++) in >> v[i];
    while (temp1 < n){
        temp2 = 0;
        for (int i = 1; i <= n - temp1; i++) temp2 += v[i];
        out << temp2 << "\n";
        temp1++;
    } return 0;
}