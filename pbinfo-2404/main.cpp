#include <fstream>
using namespace std;
ifstream cin("test.in");
ofstream cout ("test.out");
long long int solutie(long long A, long long n, int var) {
    if (n == 0) return 1;
    else {
       long long temp = solutie(A, n / 2, var);
       if (n % 2 == 0) return temp * temp % var;
       else return temp * temp % var * A % var;
    }
} int main() {
    long long int a[1001], b[1001], S = 0;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) S = S + solutie(a[i], b[i], 6669666);
    cout << S;
}