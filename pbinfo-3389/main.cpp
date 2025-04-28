#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("colturi_dr.in");
ofstream fout("colturi_dr.out");
int n, m;
int A0, A1, F0, F1;
bool a[101][101];
int p;
// complexitate O(n * (n + 1) * m / 2)
int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
           fin >> a[i][j];
    //luăm fiecare pereche de 2 linii distincte       
    for(int i = 1; i < n; ++i)
        for(int j = i + 1; j <= n; ++j)
    {
        ++p;
        int cnt1 = 0, cnt0 = 0, l, p1 = 0, p0 = 0, l1 = 0, l0 = 0;
        //căutăm prima valoarea de 1 aflată pe ambele linii
        for(l = 1; l <= m; ++l)
            if(a[i][l] == a[j][l])
               if(a[i][l] == 1)
               {
                   ++cnt1;
                   p1 = l;
                   break;
               }
               ++l;
        //căutăm toate pozițiile rămase pe care se află 1 pe ambele linii și contorizăm
        while(l <= m)
        {
            if(a[i][l] == a[j][l])
               if(a[i][l] == 1)
                   {
                       ++cnt1;
                       l1 = l;
                   }
               ++l;
        }
        //căutăm prima valoarea de 0 aflată pe ambele linii
        for(l = 1; l <= m; ++l)
            if(a[i][l] == a[j][l])
               if(a[i][l] == 0)
               {
                   ++cnt0;
                   p0 = l;
                   break;
               }
               ++l;
        //căutăm toate pozițiile rămase pe care se află 0 pe ambele linii și contorizăm
        while(l <= m)
        {
            if(a[i][l] == a[j][l])
               if(a[i][l] == 0)
                   {
                       ++cnt0;
                       l0 = l;
                   }
               ++l;
        }
        F0 += (cnt0 - 1) * cnt0 / 2; // numărul de dreptunghiuri de extrem cu vârfuri 0
        F1 += (cnt1 - 1) * cnt1 / 2; // numărul de dreptunghiuri de extrem cu vârfuri 1
        int a0, a1;
        a0 = (j - i + 1) * (l0 - p0 + 1); // aria maximă a unui dreptunghi de extrem cu vârfuri 0
        a1 = (j - i + 1) * (l1 - p1 + 1); // aria maximă a unui dreptunghi de extrem cu vârfuri 1
        A0 = max(A0, a0);
        A1 = max(A1, a1);
    }
    fout << F0 + F1 << " ";
    if(A0 > A1)
        fout << A0 << " " << F0;
    if(A0 < A1)
        fout << A1 << " " << F1;
    return 0;
}