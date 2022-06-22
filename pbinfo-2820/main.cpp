#include <fstream>
using namespace std;
ifstream in("sir11.in");
ofstream out("sir11.out");
int main() {
    int n;
   	in >> n; 
    for (int i = n; i >= 1; i--)
        if (i % 2 == 0)
            out << - i / 2 << " ";
        else
            out << (i + 1) / 2 << " ";
    return 0;
}