#include <iostream>
#include <fstream>
using namespace std;
#define NN 155
ifstream fin("joc6.in");
ofstream fout("joc6.out");
int n , a[NN], L[NN];
int main()
{
    fin >> n;
    int s1 = 0 , s2 = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j = 1 ; j <= n ; j ++)
            fin >> a[j];
        int semn;
        if(i % 2 == 1)
            semn = 1;
        else
            semn = -1;
        for(int j = n ; j > 0 ; j --)
        {
            L[j] = 1;
            for(int k = j + 1; k <= n ; k ++)
                if(semn * a[j] <= semn * a[k])
                    if(L[j] < 1 + L[k])
                        L[j] = 1 + L[k];
        }
        int Max = L[1];
        for(int j = 2 ; j <= n ; j ++)
            if(L[j] > Max)
                Max = L[j];
        if(semn == 1)
            s1 += Max;
        else
            s2 += Max;
    }
    fout << s1 << " " << s2 << endl;
    if(s1 > s2)
        fout << "UNU";
    else
        if(s1 < s2)
            fout << "DOI";
        else
            fout << "REMIZA";
    return 0;
}