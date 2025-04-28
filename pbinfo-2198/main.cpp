# include <bits/stdc++.h>
# define NM 100005
using namespace std;
ifstream f("elimin_prime.in");
ofstream g("elimin_prime.out");
int n;
bool Prime[NM];
int a[NM], aux[NM];
void ciur( int n )
{
    Prime[0] = true;
    for (int i = 2; i <= n; ++i)
        if (Prime[i] == false)
            for (int j = 2; i*j <= n; ++j)
                Prime[i*j] = true;
}
int main()
{
    f >> n;
    for(int i=1; i <= n; ++i)
        f >> a[i];
    ciur (n);
    do {
            int k = 0;
            for(int i=1; i <= n; ++i)
                if ( !Prime[i] )
                    g << a[i] << " ";
                else {
                    ++k;
                    aux[k] = a[i];
                }
            n = k;
            for(int i=1; i <= n; ++i)
                a[i] = aux[i];
    }while ( n > 0);
    return 0;
}