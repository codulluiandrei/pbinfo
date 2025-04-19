#include <iostream>
using namespace std;
void Citire(int  &, int *);
void Afisare(int , int *);
void Eratostene(int *);
bool Putere1(int , int );
void Construire(int , int * , int & ,int *);
int  v[1001];
int main()
{
    int n,x[501],m,y[1001];
    Citire(n , x);
    Eratostene(v);
    Construire(n , x , m , y);
    if(m > 0)
        Afisare(m , y);
    else
        cout << "Sirul Y este vid.";
    return 0;
}
void Citire(int & n , int * x)
{
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
        cin >> x[i];
}
void Afisare(int n , int * x)
{
    for(int i = 1 ; i <= n ; i ++)
        cout << x[i] << " ";
    cout << endl;
}
void Eratostene(int * v)
{
    for(int i = 0 ; i <= 1000 ; i ++)
        v[i] = 1;
    v[0] = v[1] = 0;
    for(int i = 2 ; i * i <= 1000; i ++)
        if(v[i] == 1)
            for(int j = 2 ; i * j <= 1000 ; j ++)
                v[i*j] = 0;
}
bool Putere1(int n , int d)
{
    // returnează true daca d apare la puterea 1 in descompunerea lui n
    int p = 0;
    while(n % d == 0)
        p ++, n /= d;
    return p == 1;
}
void Construire(int n , int * x , int & m, int * y)
{
    m = 0;
    for(int i = 2 ; i <= 1000 ; i ++)
        if(v[i] == 1)
        {
            bool OK = false;
            for(int j = 1 ; j <= n  && ! OK ; j ++)
                if(Putere1(x[j] , i))
                    OK = true;
            if(OK)
                y[++m] = i;
        }
}