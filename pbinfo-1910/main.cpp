#include <iostream>
using namespace std;
int n , m , b , r , c , r1, n1 , j, i , x[10] ,t ;
char a[1001] ;
void afis(int n1 , int u)
{
        cout << 1 ;
        c = (n1-1) / 1000 ;
        r1 = (n1-1) % 1000 ;
        if (r1==0){c-- ; r1=1000 ;}
        for ( j=1 ; j<=c ; j++) cout << a ;
        for(j=1 ; j<=r1-1 ; j++) cout << 0 ;
        cout << u << "\n";
}
int main()
{
    cin >> n ;
    for(i=0 ; i<=999 ; i++)a[i]='0';
    for ( i=1 ; i<=n ; i++ )
    {
        cin >> m >> b >> r ;
        if ( m==1 ) cout << r << "\n" ;
        else
        {
        switch (b)
        {
            case 2  :
                afis(m,r);
                break ;
            case 5  :
                afis(m,r);
                break ;
            case 10  :
                afis(m,r);
                break ;
            case 3 :
                afis(m,(r+2)%3);
                break ;
            case 9  :
                afis(m,(r+8)%9);
                break ;
            case 6 :
                afis(m,(r+2)%6);
                break ;
            case 4 :
                if ( m==2 ) afis(m,(r+2)%4);
                else afis(m,r);
                break ;
            case 7 :
                x[2] = 4 ;
                x[3] = 5 ;
                x[4] = 1 ;
                x[5] = 3 ;
                x[0] = 2 ;
                x[1] = 6 ;
                t = m % 6 ;
                afis(m,(r+x[t])%b);
                break ;
            case 8 :
                if ( m==2 ) afis(m,(r+6)%8);
                else if (m==3) afis(m,(r+4)%8);
                     else afis(m,r);
                break ;
        }
        }
    }
    return 0;
}