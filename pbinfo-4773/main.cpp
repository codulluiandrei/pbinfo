#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("specialmax.in");
    ofstream fout("specialmax.out");
    int n, maxSpecial = -1;
    fin >> n; // Citim numărul de cartonașe
    for (int i = 0; i < n / 2; i++) {
        long long numarAlina, numarCristina;
        fin >> numarAlina >> numarCristina;
        // Extragem ultimele două cifre din numărul A (Alina)
        int ultimeleDoua = numarAlina % 100;
        // Extragem primele două cifre din numărul B (Cristina)
        int primeleDoua = numarCristina;
        while (primeleDoua >= 100) {
            primeleDoua /= 10;
        }
        // Formăm numărul final
        int numarFormat = ultimeleDoua * 100 + primeleDoua;
        // Calculăm suma cifrelor pare și impare
        int sumaPare = 0, sumaImpare = 0, copie = numarFormat;
        while (copie > 0) {
            int cifra = copie % 10;
            if (cifra % 2 == 0) {
                sumaPare += cifra;
            } else {
                sumaImpare += cifra;
            }
            copie /= 10;
        }
        // Verificăm dacă este special
        if (sumaPare > sumaImpare) {
            if (numarFormat > maxSpecial) {
                maxSpecial = numarFormat;
            }
        }
    }
    // Scriem rezultatul în fișier
    fout << maxSpecial << endl;
    fin.close();
    fout.close();
    return 0;
}