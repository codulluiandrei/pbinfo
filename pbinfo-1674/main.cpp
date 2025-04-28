#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("livada1.in");
ofstream fout("livada1.out");
const int MaxVal = 1000000000;
const int NMax = 100;
const int MMax = 25000;
int A[NMax+5][MMax+5],Max[NMax+5][MMax+5];
long long Sum[NMax+5][MMax+5];
int N,M,R,Sol;
long long C;
void Read()
{
    long long x,y,z,w,u;
    fin>>N>>M>>C>>R;
    fin>>x>>y>>z>>w>>u;
    for(int i = 1; i<=M; i++)
        fin>>A[1][i];
    for(int i = 2; i<=N; i++)
        fin>>A[i][1];
    for(int i = 2; i <= N; ++i)
        for(int j = 2; j <= M; ++j)
            A[i][j] = (x * A[i - 1][j] + y * A[i][j - 1] + z * A[i - 1][j - 1] + w) % u;
}
void Precalculate()
{
    for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= M; ++j)
                {
                    Sum[i][j] = A[i][j] + Sum[i][j-1];
                    Max[i][j] = max(Max[i][j-1],A[i][j]);
                }
}
long long Find(int i, int Value)
{
    long long Crop = 0;
    int Left = 1, Right = M;
    while(Left <= Right)
    {
        int Mid = (Left+Right) / 2;
        if(Max[i][Mid] <= Value)
        {
            Crop = Sum[i][Mid];
            Left = Mid + 1;
        }
        else
            Right = Mid - 1;
    }
    return Crop;
}
bool Check(int Value)
{
    long long V[NMax],k = 0;
    for(int i = 1; i <= N; i++)
        V[++k] = Find(i,Value);
    sort(V+1,V+k+1,greater<long long>());
    long long Total = 0;
    for(int i = 1; i<=R && i<=k; i++)
        Total+=V[i];
    return (Total >= C);
}
void Solve()
{
    int Left = 1, Right = MaxVal;
    while(Left <= Right)
    {
        int Mid = (Left + Right) / 2;
        if(Check(Mid))
        {
            Sol = Mid;
            Right = Mid - 1;
        }
        else
            Left = Mid + 1;
    }
}
void Print()
{
    fout<<Sol<<"\n";
}
int main()
{
    Read();
    Precalculate();
    Solve();
    Print();
    return 0;
}