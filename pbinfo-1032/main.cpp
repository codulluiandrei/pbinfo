/*
    Solutie prof. Eugen Nodea
    streamuri
*/
# include <fstream>
# include <cmath>
# include <cstring>

using namespace std;

ifstream f("compresie.in");
ofstream g("compresie.out");

char s[1000001];
char M[1001][1001];
int L, N, nr, i, j, k;

void reconstruieste(short x1,short y1, short x2, short y2)
{
    short mx, my, x, i, j;

    //conditia de oprire
    if (x1<=x2 && y1<=y2 && k<L)
    {
        //stapaneste
        if (x1==x2 && y1==y2) M[x1][y1] = s[k++];
        else
            if (s[k]>='0' && s[k] <='9')
                {
                    x = 0;
                    while (s[k]>='0' && s[k]<='9')
                    {
                        x = x*10 + (s[k] - '0');
                        ++k;
                    }

                    //completez submatricea
                    for (i=x1; i<=x2; ++i)
                        for (j=y1; j<=y2; ++j)
                            M[i][j] = s[k];
                    ++k;
                }
        else //s[k] == '*'
            {
                //divide
                mx = (x2 + x1) >> 1; my = (y2 + y1) >> 1;
                ++k;
                // reconstruiesc submatricile A,B,C,D
                reconstruieste(x1, y1, mx, my);          //A
                reconstruieste(x1, my + 1, mx, y2);      //B
                reconstruieste(mx + 1, y1, x2, my);      //C
                reconstruieste(mx + 1, my + 1, x2, y2);  //D
            }
    }
}
int main()
{
    f.getline(s, 1000001);
    f.close();
    L = strlen(s);

    //punctul 1
    k = 0; nr = 0; j = 0;
    for (i=0; i < L; ++i)
        if (s[i] == '*') ++nr;
            else if (s[i]>='0' && s[i]<='9') k = k*10 + (s[i] - '0');
                    else if (s[i]>='a' && s[i]<='z')
                            {
                                if (s[i-1]<'a' && k) j+=k, k=0;
                                else ++j;
                            }
    N = (int) sqrt((double) j);
    g << nr << "\n";

    //punctul 3
    k=0;
    reconstruieste(1,1,N,N);
    for (i=1; i<=N; ++i)
    {
        for (j=1; j<=N; ++j)
            g << M[i][j];
        g << "\n";
    }
    g.close();
    return 0;
}
