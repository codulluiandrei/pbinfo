#include <fstream>
using namespace std;
ifstream in("cruce.in");
ofstream out("cruce.out");
long long int linie[501], coloana[501], mat[502][502];
long long int n, k, temp, maxlin, maxcol, maxim = -500 * 500 * 5001;
int main() {
    in >> n >> k;
    k--;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            in >> temp;
            linie[i] = linie[i] + temp;
            coloana[j] = coloana[j] + temp;
            mat[i][j] = temp + mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
        }
    } for (int i = 1; i <= n; i++) {
        linie[i] = linie[i] + linie[i - 1];
        coloana[i] = coloana[i] + coloana[i - 1];
    } for (int i = 1; i <= n - k; i++) {
        for (int j = 1; j <= n - k; j++) {
            temp = linie[i + k] - linie[i - 1] + coloana[j + k] - coloana[j - 1] - (mat[i + k][j + k] - mat[i - 1][j + k] - mat[i + k][j - 1] + mat[i - 1][j - 1]);
            if (temp > maxim) {
                maxim = temp; 
                maxlin = i;
                maxcol = j;
            }
        }
    } out << maxim << " " << maxlin << " " << maxcol;
    return 0;
}