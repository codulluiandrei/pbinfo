// prof. Lucian Neagu
#include <fstream>

using namespace std;

ifstream fin("pagini.in");
ofstream fout("pagini.out");

int T, t, n, p, frecv[10], i, j, f, nr, impare, x;

int main()
{
    // citesc numarul de teste
    fin >> T;

    // pentru fiecare test T, aplic algoritmul de numarare al cifrelor
    for(t=1; t<=T; t++)
    {
        // citesc numarul de carti
        fin >> n;

        // pentru fiecare caz, numerotarea cifrelor incepe de la 0.
        for(f=0; f<=9; f++)
            frecv[f] = 0;

        // parcurg fiecare carte in parte si ii numar aparitiile fiecarei cifre
        for(j=1; j<=n; j++)
        {
            // citirea numarului de pagini, pentru fiecare carte j
            fin >> p;

            // numar aparitiile fiecarei cifre, corespunzatoare cartii j
            for(nr=1; nr<=p; nr++)
            {
                x=nr;
                while (x)
                {
                    frecv[x%10]++;
                    x/=10;
                }
            }
        }

        impare = 0;

        for(i=0; i<=9; i++)
            if (frecv[i]%2)
                impare++;

        if (impare==0 || impare==1)
            fout << "DA\n";
        else
            fout << "NU\n";
    }

    return 0;
}
