#include <fstream>
using namespace std;
ifstream fin("b210.in");
ofstream fout("b210.out");
int n, m, maxi, x, k, a[50];
void conv_b2(int);
void circular();
int conv_b10();
int main()
{
    fin >> n;
    conv_b2(n);
    maxi = n;
    for (int i = 1; i < m; i++)
    {
        circular();
        x = conv_b10();
        if (x > maxi) maxi = x;
    }
    fout << maxi;
    return 0;
}
void conv_b2(int n){
    do{
        m++;
        a[m] = n % 2;
        n = n / 2;
    }while(n);
}
void circular(){
    int aux = a[1];
    for (int i = 1; i < m; i++)
        a[i] = a[i + 1];
    a[m] = aux;
}
int conv_b10(){
    int x = 0;
    for (int i = m; i >= 1; i--)
        x = x * 2 + a[i];
    return x;
}