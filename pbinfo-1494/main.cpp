#include <fstream>
#include <cstring>
using namespace std;
typedef char m_cuvinte[100][100];
//--------------------------------------------------------------------------------------------
void interschimbare(char sir1[], char sir2[]) {
    char aux[100];
    strcpy(aux, sir1);
    strcpy(sir1, sir2);
    strcpy(sir2, aux);
}
//--------------------------------------------------------------------------------------------
void sortare(m_cuvinte M, unsigned numarElem) {
    for(size_t i = 0; i < numarElem - 1; i++)
        for(size_t j = i + 1; j < numarElem; j++)
            if(strcmp(M[i], M[j]) == 1)
                interschimbare(M[i], M[j]);
}
int main(void) {
    ifstream fin("s_p_c.in");
    ofstream fout("s_p_c.out");
    char str[105];
    m_cuvinte subiect, predicat, complement;
    unsigned numarSubiecte = 0, numarPredicate = 0, numarComplemente = 0;
    while(fin >> str) {
        char tip = str[strlen(str) - 1];
        str[strlen(str) - 2] = '\0';
        if(tip == 'S')
            strcpy(subiect[numarSubiecte++], str);
        else if(tip == 'P')
            strcpy(predicat[numarPredicate++], str);
        else
            strcpy(complement[numarComplemente++], str);
    }
    sortare(subiect, numarSubiecte);
    sortare(predicat, numarPredicate);
    sortare(complement, numarComplemente);
    for(size_t i = 0; i < numarSubiecte; i++)
        for(size_t j = 0; j < numarPredicate; j++)
            for(size_t k = 0; k < numarComplemente; k++)
                fout << subiect[i] << ' ' << predicat[j] << ' ' << complement[k] << endl;
    return 0;
}