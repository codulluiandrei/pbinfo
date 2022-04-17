#include <fstream>
using namespace std;
ifstream in("maxcif.in");
ofstream out("maxcif.out");
int freq[10], temp;
int main() {
    int temp;
    while (in >> temp) freq[temp]++;
	temp = 0;
    for (int i = 0; i < 10; i++)
        if (freq[i] > temp) temp = freq[i];
    for (int i = 0; i < 10; i++) if (freq[i] == temp)
            out << i << " ";
    return 0;
}