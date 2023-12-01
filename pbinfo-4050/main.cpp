// Andrei Pirjol
#include <fstream>

using namespace std;
ifstream in ("amongus.in");
ofstream out ("amongus.out");

#define NMAX 100
int a[NMAX + 5][NMAX + 5], dx[] = {-1, 0, 1, 0, 1, 1, -1, -1}, dy[] = {0, -1, 0, 1, 1, -1, 1, -1}, cnt , cntt;

void border_matrix(int n, int m)
{
    for(int i = 0; i <= n + 1; i++)
        a[i][0] = a[i][m + 1] = 1;
    for(int i = 0; i <= m + 1; i++)
        a[0][i] = a[n + 1][i] = 1;
}

void fill (int i, int j)
{
    if(a[i][j] == 0 or a[i][j] == 2)
    {
        if(a[i][j] == 2)
            cntt++;

        a[i][j] = 3;


        for(int index1 = 0; index1 < 8; index1++)
            fill(i + dx[index1], j + dy[index1]);
    }
}

int main()
{
    int n, m, p;
    in >> p >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            in >> a[i][j];

            if(a[i][j] == 0)
                cnt++;
        }

    if(a[1][1] == 1)
        out << "misiune esuata\n";
    else
    if(p==1) out<< cnt<< endl;
    else
    {
        border_matrix(n, m);

        fill(1, 1);
        if( p==2)
        {
            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= m; j++)
                    out << a[i][j] << ' ';
                out << '\n';
            }
        }
        else out << cntt;
    }
    return 0;
}
