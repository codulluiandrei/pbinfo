#include <iostream>
using namespace std;
int Stiva[1000], nrS = 0;
int main()
{
    char S[256];
    cin >> S;
    int cnt = 0;
    for(int i = 0 ; S[i] ; i ++)
        if(S[i] == '(')
            Stiva[++nrS] = ++ cnt;
        else
        {
            cout << Stiva[nrS] << " ";
            nrS --;
        }
    return 0;
}