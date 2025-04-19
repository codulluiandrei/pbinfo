#include <fstream>
using namespace std;
int aparitii[1005];
ifstream fin("distanta.in");
ofstream fout("distanta.out");
int main()
{
    int n, dmax = 0;
    for(int i = 1; fin >> n; i++) {
        if( !aparitii[n] ) {
            aparitii[n] = i;
        }
        else {
            if(i - aparitii[n] > dmax) {
                dmax = i - aparitii[n];
            }
        }
    }
    fout << dmax;
    return 0;
}