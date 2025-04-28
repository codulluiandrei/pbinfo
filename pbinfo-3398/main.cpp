#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
ifstream fin("kps.in");
ofstream fout("kps.out");
int C;
char S[10001], * V[10001];
int K[10001], n;
int kps(char * S)
{
    int R = 0;
    for(int i = strlen(S) - 1 ; i > 0 ; i --)
        if(strstr(S , S + i) == S)
            R = strlen(S) - i;
    return R;
}
int main(){
    fin >> C;
    fin.get();
    fin.get(S, sizeof(S));
    if(C == 1)
    {
        fout << kps(S) << endl;
    }
    else
    {
        char * p = strtok(S , " ");
        while(p)
            V[++n] = p, p = strtok(NULL, " ");
        sort(V + 1 , V + n + 1, [](char * A , char * B){
            return strcmp(A , B) < 0;
        });
        int M = 0;
        for(int i = 1 ; i <= n ; i ++)
        {
            K[i] = kps(V[i]);
            M = max(M , K[i]);
        }
        for(int j =  0 ; j <= M ; j ++)
        {
            int cnt = 0;
            for(int i = 1 ; i <= n ; i ++)
                if(K[i] == j)
                    cnt ++;
            fout << cnt << " ";
            for(int i = 1 ; i <= n ; i ++)
                if(K[i] == j)
                    fout << V[i] << " ";
            fout << "\n";
        }
    }
}