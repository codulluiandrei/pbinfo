/* Oposumi - Stefan Manolache */
#include <cstdio>
#include <algorithm>
#include <math.h>
FILE *fin = fopen("oposumi.in", "r");
FILE *fout = fopen("oposumi.out", "w");
int main()
{
    int T, N;
    fscanf(fin, "%d%d", &T, &N);
    //Cerinta 1
    if (T == 1) {
        fprintf(fout, "1 ");
        for (int i = 2; i <= N; i++)
            for (int j = 1; j <= N - i + 2; j++)
                fprintf(fout, "%d ", i);
    }
    //Cerinta 2
    else {
        int K;
        fscanf(fin, "%d", &K);
        /* Calculam aria maxima a unui triunghi care are in varf K */
        int t = N*(N+1)/2 - K + 1;
        /* Vrem sa gasim p astfel incat p*(p+1)/2 <= t < (p+1)*(p+2)
         * p^2 < p*(p+1) <= 2*t < (p+1)*(p+2) < (p+2)^2
         * deci aplicam un radical, rotunjim in jos si ne asiguram ca ce am gasit e p si nu p+1
         */
        int p = (int)sqrt(2*t);
        if (p*(p+1) > 2*t)
            p--;
        /* Pozitia minima pe care o poate lua K in matrice.*/
        int poz = N + 1 - p;
        int counter1 = 1;
        int counter2 = N*(N+1)/2 - p*(p+1)/2 + 2;
        /* Pentru a afisa, punem triunghiul care are K in varf cat de in dreapta posibil
         * Umplem acest triunghi cu cele mai mari valori posibile, in ordine crescatoare
         * Restul matricii o umplem cu restul valorilor, din nou in ordine crescatoare
         */
        for (int i = 1; i <= N; i++) {
            //Restul matricii
            for (int j = 1; j <= poz - 1 && j <= i; j++) {
                fprintf(fout, "%d ", counter1);
                counter1++;
                if (counter1 == K) //sarim peste valoarea K pentru ca este deja in matrice
                    counter1 = K + 1;
            }
            //triunghiul care are in varf K
            for (int j = poz; j <= i; j++) {
                if (i == poz)
                    fprintf(fout, "%d ", K);
                else {
                    fprintf(fout, "%d ", counter2);
                    counter2++;
                }
            }
            fprintf(fout, "\n");
        }
    }
}