#include <bits/stdc++.h>
using namespace std;

int cmmdc(int a, int b)
{   while(a != b)
    {  if(a > b)a -= b;
         else   b -= a;
    }
    return a;
}
void Raza(int a, int b, int &nrSchimb)
{    nrSchimb = (a + b) / cmmdc(a , b) - 2;
}
int main()
{   int a,b,nrSchimb;
    cin >> a;
    cin >> b;
    Raza(a, b, nrSchimb);
    cout << nrSchimb;
    return 0;
}