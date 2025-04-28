#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("moscraciun5.in");
ofstream fout("moscraciun5.out");
int n,m, a[102][102];
const int dx[]={0 , 0 , 1 , -1}, dy[]={1 , -1 , 0 , 0};
int S = 0; // suma cadourilor de pe banchiza lui Moș Crăciun
void fill(int i , int j)
{
    S += a[i][j];
    a[i][j] = -1;
    for(int k = 0 ; k < 4 ; k ++)
        if(a[i+dx[k]][j+dy[k]] > 0)
            fill(i+dx[k] , j+dy[k]);
}
int main(){
    fin >> n >> m;
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1 ; j <= m ; j ++)
            fin >> a[i][j];
    fin.close();
    //facem fill din pozitia initiala a lui Mos Craciun
    fill(1 , 1);
    fout << S;
    fout.close();
    return 0;
}