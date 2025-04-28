// prof. Mircea Lupse-Turpan - Liceul Teoretic Grigore Moisil Timisoara - 100 puncte
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("rover.in");
ofstream fout("rover.out");
struct Cell
{
    int x, y;
    Cell * next;
};
const int NMax = 505;
const int oo = 10000;
int A[NMax][NMax],DP[NMax][NMax];
int V,N,G;
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
Cell * First, * Last;
void Add_Front(int V1, int V2)
{
    Cell * p = new Cell;
    p -> x = V1;
    p -> y = V2;
    p -> next = First;
    if(!First)
        Last = p;
    First = p;
}
void Add_Back(int V1, int V2)
{
    Cell * p = new Cell;
    p -> x = V1;
    p -> y = V2;
    p -> next = NULL;
    if(!First)
        First = p;
    else
        Last -> next = p;
    Last = p;
}
void Delete_Front()
{
    Cell * p;
    p = First;
    First = First -> next;
    delete p;
    if(!First) Last = NULL;
}
bool isEmpty()
{
    return (First == NULL);
}
void Read()
{
    fin >> V >> N;
    if(V == 1) fin >> G;
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j)
            fin >> A[i][j];
}
inline bool Inside(int x, int y)
{
    return ( (x >= 1) && (x <= N) && (y >= 1) && (y <= N) );
}
void Solve1()
{
    memset(DP,-1,sizeof(DP));
    Add_Back(1,1);
    DP[1][1] = 0;
    while(!isEmpty())
    {
        int X = First -> x, Y = First -> y;
        Delete_Front();
        for(int k = 0; k < 4; k++)
        {
            int NewX = X + dx[k], NewY = Y + dy[k];
            if(Inside(NewX,NewY) && DP[NewX][NewY] == -1)
            {
                if(A[NewX][NewY] < G)
                {
                    DP[NewX][NewY] = DP[X][Y] + 1;
                    Add_Back(NewX,NewY);
                }
                else
                {
                    DP[NewX][NewY] = DP[X][Y];
                    Add_Front(NewX,NewY);
                }
            }
        }
    }
    fout << DP[N][N] << "\n";
}
bool Lee(int Value)
{
    memset(DP,-1,sizeof(DP));
    Add_Back(1,1);
    DP[1][1] = 0;
    while(!isEmpty())
    {
        int X = First -> x, Y = First -> y;
        Delete_Front();
        for(int k = 0; k < 4; k++)
        {
            int NewX = X + dx[k], NewY = Y + dy[k];
            if(Inside(NewX,NewY) && DP[NewX][NewY] == -1)
            {
                if(A[NewX][NewY] >= Value)
                {
                    DP[NewX][NewY] = DP[X][Y] + 1;
                    Add_Back(NewX,NewY);
                }
            }
        }
    }
    return (DP[N][N] != -1);
}
void Solve2()
{
    int Left = 1, Right = oo, Sol = -1;
    while(Left <= Right)
    {
        int Mid = (Left + Right) / 2;
        if(Lee(Mid))
        {
            Sol = Mid;
            Left = Mid + 1;
        }
        else
            Right = Mid - 1;
    }
    fout << Sol << "\n";
}
int main()
{
    Read();
    if(V == 1)
        Solve1();
    else
        Solve2();
    return 0;
}