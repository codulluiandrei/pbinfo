#include <fstream>

struct _uniforma {
    int marime, numarCopii;
};

int main() {
    std::ifstream fin("serbare.in");
    std::ofstream fout("serbare.out");
    _uniforma uniforma[15], aux;
    int copii, uniforme, marimi[15] = {0};
    fin >> copii >> uniforme;
    for(int i = 1; i <= copii; i++) {
        int marime, nrCopii;
        fin >> nrCopii >> marime;
        marimi[marime] += nrCopii;
    }

    for(int i = 1; i <= uniforme; i++) {
        uniforma[i].marime = i;
        uniforma[i].numarCopii = marimi[i];
    }

    for(int i = 1; i < uniforme; i++)
        for(int j = i + 1; j <= uniforme; j++)
            if(uniforma[i].numarCopii < uniforma[j].numarCopii) {
                aux = uniforma[i];
                uniforma[i] = uniforma[j];
                uniforma[j] = aux;
            }

    for(int i = 1; i <= uniforme; i++)
        fout << uniforma[i].marime << ' ';
    return 0;
}
