#include <iostream>
using namespace std;
int P;
long long N;
long long fact[21];                   
int cifre[21] = {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; // ce cifre au fost deja folosite (vor avea 0 pe pozitia lor)
int main()
{
    cin >> P >> N;
    fact[0]=1;
    for(int i=1; i<=P; i++)
        fact[i] = i*fact[i-1]; 
    for(int i=P; i>=1; i--)    
    {
        int idx=1;
        while(N > fact[i-1])
        {
            N -= fact[i-1];
            idx++;
        }
        int poz = 1;
        while (cifre[poz]==0) poz++;
        while (idx > 1)
        {
            while (cifre[poz]==0) poz++;
            idx--;
            poz++;
        }
        while (cifre[poz]==0) poz++;
        cifre[poz]=0;
        cout << poz << ' ';
    }
    return 0;
}