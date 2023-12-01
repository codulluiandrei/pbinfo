#include <fstream>
#include <algorithm>
#define Nmax 100001

using namespace std;

long long a[Nmax], N;

int main() {

    ifstream f("gravitatie.in");
    ofstream g("gravitatie.out");

    f >> N;

    for(int i = 0; i < N; ++i) {
        f >> a[i];
    }

    sort(a, a + N);

    int sol = 1;

    for(int i = 1; i < N; ++i) {
        if(a[i] != a[i-1])
            ++sol;
    }

    g << sol;

    return 0;
}
