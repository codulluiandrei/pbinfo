#include <fstream>
using namespace std;
ifstream in("lungime1.in");
ofstream out("lungime1.out");
int freq[100001], n, lungime = 0;
int main() {
    in >> n;
    for (int i = 1; i <= n; ++i) {
        int temp; in >> temp;
        if (freq[temp] == 0) freq[temp] = i;
        else if (i - freq[temp] > lungime)
                lungime = i - freq[temp] + 1;
    } out << lungime;
    return 0;
}