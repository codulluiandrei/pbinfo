#include <fstream>
using namespace std;
ifstream in("nrlipsa1.in");
ofstream out("nrlipsa1.out");
int freq[100];
int main() {
    int n;
    while (in >> n) if (n > 9 && n < 100) freq[n] = 1;
    int val1 = -1, val2 = -1;
    for (int i = 10; i < 100 && val1 == -1; i = i + 2)
        if (freq[i] == 0) val1 = i;
    for (int i = 98; i > 9 && val2 == -1; i = i - 2)
        if (freq[i] == 0) val2 = i;
    if (val1 == val2) out << "nu exista";
    else out << val1 << " " << val2;
    return 0;
}