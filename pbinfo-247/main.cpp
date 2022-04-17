#include <fstream>
using namespace std;
ifstream in("cifreord1.in");
ofstream out("cifreord1.out");
int freq[10];
int main() {
    int temp;
    while (in >> temp)
        do {
            freq[temp % 10]++;
            temp = temp / 10;
        } while (temp != 0);
    temp = 0;
    for (int i = 9; i >= 0; --i)
        for (int ap = 1; ap <= freq[i]; ++ap) {
            out << i << " ";
            temp++;
            if (temp % 20 == 0) out << endl;
        } return 0;
}