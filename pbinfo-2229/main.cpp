#include <bits/stdc++.h>
#define LG 1001
using namespace std;
/// Operatii cu numere mari care au cel mult 100 de cifre
/// In a[0] avem lungimea, in a[1] cifra unitatilor,
/// in a[2] - cifra zecilor etc
/// De exemplu, pentru numarul 14368 avem a=(5,8,6,3,4,1)
ofstream g("numere20.out");
ifstream f("numere20.in");
typedef int bigint[LG];
///Transform numar mare citit ca un sir de caractere in reprezentarea data
void Set(bigint a,char x[])
{
    int i,n;
    memset(a, 0, LG * 2);
    n = a[0] = strlen(x);
    for(i = 1; i <= n; i++)
        a[i] = x[n - i] - '0';
}
void copie(bigint A, bigint B) /// A=B
{
     memcpy(A, B, LG * 2);
}
///Scriu in fisier un numar mare
void scrie(bigint a)
{
    int i;
    for(i = a[0]; i >= 1; i--)
        g << a[i];
    g << endl;
 }
///Adun doua numere mari
void suma(bigint A,bigint B,bigint C)  // C=A+B
{
    int i, r, s;
    memset(C, 0, LG * 2);
    memcpy(C, A, LG * 2);
    if(A[0] > B[0]) C[0] = A[0];
    else C[0] = B[0];
    i = 1; r = 0;
    while(i <= B[0])
    {
        s = C[i] + B[i] + r;
        r = s / 10;
        C[i] = s % 10;
        i++;
    }
    while(r)
    {
        s = C[i] + r;
        r = s / 10;
        C[i] = s % 10;
        i++;
    }
    if(i - 1 > C[0]) C[0]++;
}
void dif(bigint A, bigint B, bigint C) /// C=A-B
{
    int i, j;
    memcpy(C, A, LG * 2);
    for(i = 1; i <= C[0]; i++)
        if(C[i] >= B[i]) C[i] = C[i] - B[i];
        else
        {
            j = i + 1;
            while(C[j] == 0)
            {
                C[j] = 9;
                j++;
            }
            C[j]--;
            C[i] = C[i] + 10 - B[i];
        }
    i = C[0];
    while(i > 1 && C[i] == 0)i--;
    C[0] = i;
}
void divide_mare_mic(bigint a,int b,bigint c) /// c=a/b
{
    int i, j, k, x, y[LG];
    memset(c, 0, LG * 2);
    x = 0; i = a[0];
    while(x < b && i > 0)
    {
        x = x * 10 + a[i];
        i--;
    }
    x = x / 10;
    i++;
    for(j = 0; i > 0; i--, j++)
    {
        x = x * 10 + a[i];
        y[j] = x / b;
        x = x % b;
    }
    if(j == 0)
    {
        c[0] = 1;
        c[1] = 0;
    }
    else
	{
        c[0] = j;
        for(i = 1,k = j - 1; k >= 0; i++, k--)
            c[i] = y[k];
	}
}
int main()
{
     char nn[101];
     int u, v;
     bigint n, nr1, nr2, nr3, nr4, nr5, nr;
     f >> nn >> u >> v;
     Set(n, nn);
     divide_mare_mic(n, u, nr1);   /// nr1=n/u;
     divide_mare_mic(n, v, nr2);   /// nr2=n/v;
     suma(nr1, nr2, nr3);          /// nr3=nr1+nr2;
     divide_mare_mic(n, u * v, nr4); /// nr4=n/(u*v);
     dif(nr3, nr4, nr5);           /// nr5=nr3-nr4;
     dif(n, nr5, nr);
     scrie(nr);
     g.close();
     return 0;
}