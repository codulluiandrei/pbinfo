#include <iostream>
#include <fstream>
int n, v[10], x[10];
std :: ifstream fin("produscartezian2.in");
std :: ofstream fout("produscartezian2.out");
void afis(int k){
    for(int i=1 ; i <= k ; ++i)
        fout << x[i] << " ";
    fout << std :: endl;
}
void back(int k){
    for(int i = 1; i <= v[k] ; ++i)
    {
        x[k]=i;
        if(k == n)
            afis(k);
        else
            back(k+1);
    }
}
int main(){
	fin >> n;
    for(int i = 1 ; i <= n ; i ++)
        fin >> v[i];
	back(1);
	return 0;
}