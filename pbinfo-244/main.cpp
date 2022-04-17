#include <fstream>
using namespace std;
ifstream in("cifreord.in");
ofstream out("cifreord.out");
int freq[10], nr, temp;
int main() {
    in >> nr;
    for (int i = 1; i <= nr; i++) {
        in >> temp;
        freq[temp]++;
    } temp = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 1; j <= freq[i]; j++) {
            out << i << " ";
            temp++;
            if (temp % 20 == 0) out << endl;
        } return 0;
}