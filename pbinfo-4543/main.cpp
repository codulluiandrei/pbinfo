#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("moscraciun4.in");
ofstream fout("moscraciun4.out");
int n,m, a[102][102];
const int dx[]={0 , 0 , 1 , -1}, dy[]={1 , -1 , 0 , 0};
int nr_spiridusi_buni, nr_spiridusi_rai, //numarul de spiridusi buni/rai de pe banchiza lui Mos Craciun
    imc, jmc; // coordonatele lui Mos Craciun
void fill(int i , int j)
{
    if(a[i][j] == 3)
        nr_spiridusi_buni ++;
    if(a[i][j] == 4)
        nr_spiridusi_rai ++;
    a[i][j] = -1;
    for(int k = 0 ; k < 4 ; k ++)
        if(a[i+dx[k]][j+dy[k]] > 0)
            fill(i+dx[k] , j+dy[k]);
}
int main(){
    fin >> n >> m;
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1 ; j <= m ; j ++)
        {
            fin >> a[i][j];
            if(a[i][j] == 2)
                imc = i, jmc = j;
        }
    fin.close();
    //facem fill din pozitia initiala a lui Mos Craciun
    fill(imc ,jmc);
    fout << nr_spiridusi_buni << " " << nr_spiridusi_rai;
    fout.close();
    return 0;
}