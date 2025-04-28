#include <iostream>
#include <fstream>
#include <queue>
#define INF 1000000000
using namespace std;
ifstream  fin("ubuph.in");
ofstream fout("ubuph.out");
int A[1001][1001], B[1001][1001], n, m, im, jm, ic, jc;
const int di[] = {1,-1,0,0}, dj[]={0,0,1,-1};//deviatiile
queue<pair<int, int> > Q;// initializare coada
bool Inside(int i , int j){
    return 1 <= i && i <= n && 1 <= j && j <= m;
}//functie de verificare daca pozitia curenta se afla in matrice
void citire()
{fin >> n >> m;
        for(int i =1 ; i <= n ; i ++)
        for(int j = 1 ; j <= m ; j ++)
            {fin >> A[i][j];
             B[i][j] = INF;
           }  
    fin >> im >> jm >> ic >> jc;
}
void Lee()
{   B[ic][jc] = A[ic][jc];
    while(! Q.empty())
    {
        pair<int,int> P = Q.front();
        for(int k = 0 ; k < 4 ; k ++)
        {
            int i = P.first + di[k] ,j = P.second + dj[k];
            if( Inside(i,j) && B[i][j] > B[P.first][P.second] + A[i][j])
                B[i][j] = B[P.first][P.second] + A[i][j], Q.push(make_pair(i,j));
        }
        Q.pop();
    }
}
int main(){
    citire();
    Q.push(make_pair(ic,jc)); 
  Lee();
    fout << B[im][jm];
    fin.close(), fout.close();//ichiderea fisierelor
    return 0;
}