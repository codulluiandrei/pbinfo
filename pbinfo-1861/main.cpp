#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <cstring>
#define NN 100001
using namespace std;
fstream fin("topsort.in", ios::in), fout("topsort.out", ios::out);
int n, v[NN];
list<int> F;
vector<int> G[NN];
void dfs(int x){
    v[x] = 1;
    for(vector<int>::iterator I = G[x].begin(); I < G[x].end() ; I++)
        if(v[*I] == 0)
            dfs(*I);
    F.push_front(x);
}
int main(){
    fin >> n;
    int m;
    for(fin >> m ; m ; m --)
    {
        int x , y;
        fin >>x >> y;
        G[x].push_back(y);
    }
    for(int i = 1 ; i <= n ; i++)
        if(v[i] == 0)
            dfs(i);
    for(list<int>::iterator x = F.begin() ; x != F.end() ; x ++)
        fout << *x << " ";
    return 0;
}