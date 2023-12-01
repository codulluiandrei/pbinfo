#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("permeuler.in");
ofstream fout("permeuler.out");

int fi(int n)
{
    int p = n , d = 2;
    while(n > 1)
    {
        if(n % d == 0)
        {
            p = p / d * (d - 1);
            while(n % d == 0) n /= d;
        }
        d += (d & 1) ? 2 : 1;;
        if(d * d > n)
            d = n;
    }
    return p;
}

bool verif(int x , int y)
{
    for(int c = 0 ; c <= 9 ; c ++)
    {
        int a = x , b = y , ca = 0 , cb = 0;
        while(a)
        {
            if(a % 10 == c) ca ++; 
            a /= 10;
        }
        
        while(b)
        {
            if(b % 10 == c) cb ++; 
            b /= 10;
        }
        
        if(ca != cb)
            return 0;
        
    }
    return 1;
}

int main()
{
    
    int n , nmin = 1000000000, fimin = 1, f, ok = false;
    while(fin >> n)
    {
        f = fi(n);
        if(verif(n,f))
        {
            ok = true;
            if(1LL * n * fimin < 1LL * f * nmin)
                fimin = f, nmin = n;
        }
    }
    if(!ok)
        nmin = 0;
    fout << nmin;
    return 0;
}
