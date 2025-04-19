#include <fstream>
using namespace std;
ifstream fin ("vacantadevara.in");
ofstream fout ("vacantadevara.out");
int main ()
{
    int N;
    fin >> N;   // Citim numarul de cifre.
    int x;
    int A[10] = {0};            // In acest vector stocam numarul de aparitii ale cifrelor din intervalul [0,9].
    for (int i=1; i<=N; i++)
    {
        fin >> x;               // Pentru fiecare cifra citita...
        A[x]++;                 // Marim numarul de aparitii ale acesteia.
    }
    int pos = 1;            // Determinam prima cifra diferita de 0 care apare in scrierea numarului nostru.
    while (A[pos] == 0)
        pos++;
    fout << pos;    // Afisam o singura data prima cifra existenta in numar
    A[pos]--;       // si decrementam numarul acesteia de aparitii.
    for (int i=0; i<=9; i++)        // Pentru fiecare cifra din intervalul [0,9]...
        for (int j=1; j<=A[i]; j++)
            fout << i;              // O afisam de A[i] ori (pentru ca A[i] reprezinta numarul de aparitii ale cifrei i).
    return 0;
}