# include <bits/stdc++.h>
using namespace std;

ifstream f("extindere.in");
ofstream g("extindere.out");

int n;

int main()
{
    f >> n;

    int p = 1;
    while( p * 4 < n )
        p *= 4;

    bool op = 0; /// codific, pentru usurinta cu {0,1}, nu cu {1,2}
    while( n > 4){
        if( n > p && n <= 3*p ) op ^= 1;
        n = (n-1) % p + 1;
        p /= 4;
    }


    if( op ){
        if ( n == 2 || n == 3 ) g << "1\n";
        if ( n == 1 || n == 4 ) g << "2\n";
    }
    else{
        if ( n == 2 || n == 3 ) g << "2\n";
        if ( n == 1 || n == 4 ) g << "1\n";
    }

    return 0;
}
