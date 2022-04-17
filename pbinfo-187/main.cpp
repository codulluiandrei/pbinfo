#include <fstream>
using namespace std;
ifstream in("ciffrecv.in");
ofstream out("ciffrecv.out");
int freq[10], nr;
int main() {
    while (in >> nr) freq[nr]++;
    if (freq[7]) {
        out << 7 << " " << freq[7];
        return 0;
    } if (freq[5]) {
        out << 5 << " " << freq[5];
        return 0;
    } if (freq[3]) {
        out << 3 << " " << freq[3];
        return 0;
    } if (freq[2]) {
        out << 2 << " " << freq[2];
        return 0;
    }
}