#include <fstream>
#include <cstring>
using namespace std;
ifstream f("minlex.in");
ofstream g("minlex.out");
char S[100001];
int N;
bool compara(char *S, int i, int j)
{
    int k;
    for (k=0;k<N;k++)
    {
        if (S[i]<S[j]) return false;
        if (S[i]>S[j]) return true;
        i=(i+1)%N;
        j=(j+1)%N;
    }
    return true;
}
int minlex(char *S)
{
    int poz=0, i;
    for (i=1;i<N;i++)
        if (compara(S,poz,i)) poz=i;
    return poz;
}
int main()
{
    f>>S;
    f.close();
    N=strlen(S);
    g<<minlex(S)<<'\n';
    g.close();
    return 0;
}