#include <fstream>
#include <iostream>
#define Nmax 102
#define Cmax Nmax*Nmax
#define InFile  "castel1.in"
#define OutFile "castel1.out"
using namespace std;
short A[Nmax][Nmax], Viz[Nmax][Nmax];
short N;
short C;
short ValBit(short No, short Pos)
{
    return ((1<<Pos) & No)>>Pos;
}
void Fill(short lin, short col, short &Aria, short &elin, short &ecol)
{
    short i, j;
    short Clin[Cmax], Ccol[Cmax];
    short CrrLin, CrrCol, Prim, Ultim;
    Aria = 0;
    elin = lin; ecol = col;
    Prim = 1; Ultim = 1; Clin[Ultim] = lin; Ccol[Ultim] = col;
    while(Prim <= Ultim)
    {
        CrrLin = Clin[Prim]; CrrCol = Ccol[Prim++];
        Viz[CrrLin][CrrCol] = 1;
        Aria++;
        if(elin<=CrrLin && ecol<=CrrCol) elin = CrrLin, ecol = CrrCol;
        if(!ValBit(A[CrrLin][CrrCol], 3) && !Viz[CrrLin-1][CrrCol]) //Nord
            {Ultim++; Clin[Ultim] = CrrLin-1; Ccol[Ultim] = CrrCol; Viz[CrrLin-1][CrrCol] = 1; }
        if(!ValBit(A[CrrLin][CrrCol], 2) && !Viz[CrrLin][CrrCol+1]) //Est
            {Ultim++; Clin[Ultim] = CrrLin; Ccol[Ultim] = CrrCol+1; Viz[CrrLin][CrrCol+1] = 1; }
        if(!ValBit(A[CrrLin][CrrCol], 1) && !Viz[CrrLin+1][CrrCol]) //Sud
            {Ultim++; Clin[Ultim] = CrrLin+1; Ccol[Ultim] = CrrCol; Viz[CrrLin+1][CrrCol] = 1; }
        if(!ValBit(A[CrrLin][CrrCol], 0) && !Viz[CrrLin][CrrCol-1]) //Vest
            {Ultim++; Clin[Ultim] = CrrLin; Ccol[Ultim] = CrrCol-1; Viz[CrrLin][CrrCol-1] = 1; }
    }
}
int main()
{
    int i, j, k;
    short Slin[Cmax], Scol[Cmax], Svf = 0;
    short slin, scol, elin, ecol, Aria;
    short maxil, maxic, maxfl, maxfc, AriaMax=0, NrCamere;
    ifstream Fin(InFile);
    //citire
    Fin >> C >> N;
    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++)
         {
            Fin >> A[i][j];
            if(A[i][j] == 9 || A[i][j] == 11 || A[i][j] == 15 || A[i][j] == 13)
            {
                Svf++; Slin[Svf] = i; Scol[Svf] = j;
            }
         }
    Fin.close();
    //initializare
    for(i=0;i<=N+1;i++)
    {
         Viz[0][i] = Viz[N+1][i] = 15;
         Viz[i][0] = Viz[i][N+1] = 15;
    }
    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++) Viz[i][j] = 0;
    //rezolvare
    NrCamere = Svf;
    while(Svf)
    {
        slin = Slin[Svf]; scol = Scol[Svf];
        Fill(slin, scol,Aria, elin, ecol);
        Svf--;
        if(Aria>=AriaMax) maxil = slin, maxic = scol, maxfl = elin, maxfc = ecol, AriaMax = Aria;
    }
    ofstream Fou(OutFile);
    if ( C == 1) Fou<<NrCamere<<'\n';
    if ( C == 2) Fou<<AriaMax<<'\n';
    if ( C == 3)Fou<<maxil<<' '<<maxic<<' '<<maxfl<<' '<<maxfc<<'\n';
    Fou.close();
    return 0;
} 