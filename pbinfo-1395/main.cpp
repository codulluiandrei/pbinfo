#include <iostream>
#include <fstream>
using namespace std;
#define NN 103
ifstream fin ("msuma.in");
ofstream fout("msuma.out");
struct Matrice{
    int nrLin, nrCol;
    int Tablou[NN][NN];
};
void Citire(Matrice &A, istream & in)
{
    in >> A.nrLin >> A.nrCol;
    for(int i = 1 ; i <= A.nrLin ; i ++)
        for(int j = 1 ; j <= A.nrCol ; j ++)
            in >> A.Tablou[i][j];
}
void Afisare(Matrice A, ostream & out)
{
    out << A.nrLin << " " << A.nrCol << endl;
    for(int i = 1 ; i <= A.nrLin ; i ++)
    {
        for(int j = 1 ; j <= A.nrCol ; j ++)
            out << A.Tablou[i][j] << " ";
        out << endl;
    }
}
Matrice Suma(Matrice A, Matrice B)
{
    Matrice S;
    S.nrLin = A.nrLin, S.nrCol = A.nrCol;
    for(int i = 1 ; i <= A.nrLin ; i ++)
        for(int j = 1 ; j <= A.nrCol ; j ++)
            S.Tablou[i][j] = A.Tablou[i][j] + B.Tablou[i][j];
    return S;
}
int main()
{
    Matrice A, B, S;
    Citire(A, fin); 
    Citire(B, fin);
    S = Suma(A , B);
    Afisare(S, fout);
    return 0;
}