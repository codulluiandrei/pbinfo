#include <fstream>
using namespace std;
ifstream fin("control2.in");
ofstream fout("control2.out");
int main(void)
{
    int greutati[100], numarGreutati, aparitii[100], numarApariti=0, numarControl=0, elementeSumaControl[2], estePrim = 1;
    elementeSumaControl[0] = elementeSumaControl[1] = 0;
    /* citirea greutatilor */
    fin >> numarGreutati;
    for (int i = 0; i < numarGreutati; i++) {
        fin >> greutati[i];
    }
    /* ordonarea crescatoare a acestora */
    for (int i = 0; i < numarGreutati - 1; i++) {
        for (int j = i + 1; j < numarGreutati; j++) {
            if (greutati[i] > greutati[j]) {
                int aux = greutati[i];
                greutati[i] = greutati[j];
                greutati[j] = aux;
            }
        }
    }
    /* le grupam dupa numarul de aparitii */
    {
        int i = 0;
        while(i < numarGreutati) {
            int count = 1;
            if (greutati[i] == greutati[i+1]) {
                while (greutati[i] == greutati[i+1] && i < numarGreutati) {
                    count++;
                    i++;
                }
            }
            aparitii[numarApariti++] = count;
            i++;
        }
    }
    /* parcurgem greutatile cate 3 */
    for(int i = 0; i < numarApariti / 3 * 3; i += 3) {
        elementeSumaControl[aparitii[i] % 2 == aparitii[i + 1] % 2 && aparitii[i] % 2 == aparitii[i + 2] % 2]++;
    }
    /* construim numarul de contorl */
    numarControl = elementeSumaControl[0] + elementeSumaControl[1] * 10;
    /* verificam daca este prim */
    if (numarControl % 2==0)
    {
        estePrim = (numarControl == 2);
    }
    else
    {
        for(int d = 3; d * d <= numarControl; d += 2) {
            if(numarControl % d == 0) {
                estePrim = 0;
                break;
            }
        }
    }
    fout << numarControl << '\n' << estePrim;
    return 0;
}