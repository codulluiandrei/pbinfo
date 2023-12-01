#include <fstream>
using namespace std;

ifstream fin("inima.in");
ofstream fout("inima.out");

int n, puls[100000];

int main()
{
    fin >> n;
    for(int i = 0; i < n; ++i)
        fin >> puls[i];

    int activitate = 0;
    int w, i = 0, j = n - 1;

    while (i < j) {
        int h = min(puls[i], puls[j]);
        activitate = max(activitate, (j - i) * h);
        while (puls[i] <= h && i < j) 
            i++;
        while (puls[j] <= h && i < j) 
            j--;
    }

    fout << activitate;
    return 0;
}
