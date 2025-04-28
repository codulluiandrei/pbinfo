/**
  Programare dinamica metoda mixta:
  dp[i,j]=valorile distincte posibile care se obtin daca din sirul de
          petitori i, i+1, ..., j ramane unul singur
  dp[i,j]= este un vector de aparitii de lungime 20, dp[i,j,k]=1
          daca se poate obtine suma k (k=0..20)
  Solutia se afla in dp[1][n], afisandu-se indicii bitilor setati cu 1
  Complexitate O(n x n x n), cu o constanta 21 x 21.
*/
#include <bits/stdc++.h>
#define nmax 52
#define inFile "nunta1.in"
#define outFile "nunta1.out"
using namespace std;
int a[nmax], n;
bitset<22> dp[nmax][nmax];
inline int Modul(int x)
{
    if (x < 0) return -x;
    return x;
}
void Citire()
{
    ifstream fin(inFile);
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    fin.close();
}
void Seteaza(int p, int k, int q)
{
    int i, j;
    for (i = 0; i <= 20; i++)
        for (j = 0; j <= 20; j++)
            if (dp[p][k][i] == 1 && dp[k+1][q][j] == 1)
                dp[p][q][Modul(i-j)] = 1;
}
void Rezolva()
{
    int i, j, pas, k;
    /// initializare diagonala principala
    for (i = 1; i <= n; i++)
        dp[i][i][a[i]] = 1;
    /// initializare urmatoarea diagonala
    for (i = 1; i < n; i++)
        dp[i][i + 1][Modul(a[i]-a[i + 1])] = 1;
    /// procesarea restului matricei
    for (pas = 2; pas < n; pas++)
        for (i = 1; i <= n - pas; i++)
        {
            j = i + pas;
            for (k = i; k < j; k++)
                Seteaza(i, k, j);
        }
}
void Afisare()
{
    int i;
    ofstream fout(outFile);
    fout << dp[1][n].count() << "\n";
    for (i = 0; i <= 20; i++)
        if (dp[1][n][i] == 1) fout << i << " ";
    fout << "\n";
    fout.close();
}
int main()
{
    Citire();
    Rezolva();
    Afisare();
    return 0;
}