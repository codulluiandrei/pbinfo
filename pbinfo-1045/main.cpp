//Marinel Serban
//O(k)
#include <fstream>

using namespace std;

ifstream fin("imprimanta.in");
ofstream fout("imprimanta.out");

long long N, K, s_max, s;
int cifra, ace, min_ace = 25, max_cifra, i;

int main()
{
    fin >> N >> K;
//punctul a)
    while (N)
    {
        cifra = N % 10;
        N /= 10;
        switch (cifra)
        {
            case 0:
            case 6:
            case 9: ace = 12; break;
            case 1: ace = 5; break;
            case 2:
            case 3:
            case 5: ace = 11; break;
            case 4: ace = 9; break;
            case 7: ace = 7; break;
            case 8: ace = 13; break;
        }
        if (ace < min_ace)
        {
            min_ace = ace;
            switch (ace)
            {
                case 12: max_cifra = cifra; break;
                case 11: max_cifra = cifra; break;
                case 5: max_cifra = 1; break;
                case 7: max_cifra = 7; break;
                case 9: max_cifra = 4; break;
                case 13: max_cifra = 8; break;
            }
        }
        else
            if (ace == min_ace)
            switch (ace)
            {
                case 12: if (cifra>max_cifra) max_cifra = cifra; break;
                case 11: if (cifra>max_cifra) max_cifra = cifra; break;
            }
    }
    fout << max_cifra << '\n';
//punctul b)
    if (K % 5 == 0)
        for (i = 1; i <= K / 5; ++i) fout << 1;   //numai 1
    else
        if (K  % 5 == 1)
        {
            if (K == 16) fout << 74;              //caz particular
            else
            {
                fout << 777;                      //21 ace (3 * 7)
                for (i = 1; i <= (K - 21) / 5; ++i) fout << 1;//restul 1 (cate 5 ace)
            }
        }
        else
            if (K % 5 == 2)
            {
                fout << 7;                                     //7 ace (2+5)
                for (i = 1; i <= (K - 7) / 5; ++i) fout << 1;  //restul 1
            }
            else
                if (K % 5 == 3)
                {
                    fout << 8;                                      //13 ace (3+2*5)
                    for (i = 1; i <= (K  - 13)/ 5; ++i) fout << 1;  //restul 1
                }
                else
                {
                    fout << 77;                                    //9 ace (4+5)
                    for (i = 1; i <= (K - 14) / 5; ++i) fout << 1;
                }
    fout << '\n';
    fout.close();
    return 0;
}
