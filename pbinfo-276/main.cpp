#include <fstream>
using namespace std;
ifstream in("pareimpare.in");
ofstream out("pareimpare.out");
int freq[100];
int main() {
    int temp;
    while (in >> temp)
        freq[temp] = 1;
    for (int i = 1; i < 100; i = i + 2)
        if (freq[i]) out << i << " ";
    out << endl;
    for (int i = 98; i >= 0; i = i - 2)
        if (freq[i]) out << i << " ";
    out << endl;
    return 0;
}