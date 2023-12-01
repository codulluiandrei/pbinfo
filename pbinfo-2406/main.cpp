#include <fstream>
 
using namespace std;
 
int n, t[4];
int a[1005];
 
void Citire()
{
    int i;
    ifstream fin("sort.in");
    fin >> n;
    for(i = 0; i < n; i++)
    {
        fin >> a[i];
        t[a[i]] ++;
    }
    fin.close();
}
 
void Rezolvare()
{
    int ans, i, s12, s13, s21, s31, s23, s32;
    s12 = s21 = s13 = s31 = s23 = s32 = 0;
 
    for (i = 0; i < t[1]; i++)
    {
        if (a[i] == 2) s12++;
        if (a[i] == 3) s13++;
    }
 
    for (i = t[1]; i < t[1] + t[2]; i++)
    {
        if (a[i] == 1) s21++;
        if (a[i] == 3) s23++;
    }
 
    for (i = t[1] + t[2]; i < t[1] + t[2] + t[3]; i++)
    {
        if (a[i] == 1) s31++;
        if (a[i] == 2) s32++;
    }
 
    ans = min(s12, s21) + min(s13, s31) + min(s23, s32) +
         2 * (max(s12, s21) - min(s12, s21));
 
    ofstream fout("sort.out");
    fout << ans << "\n";
    fout.close();
}
 
int main()
{
    Citire();
    Rezolvare();
    return 0;
}