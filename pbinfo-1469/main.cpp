#include <fstream>
using namespace std;
ifstream f("concursinfo.in");
ofstream g("concursinfo.out");
long long a , b , c , x , max1 , max2 , max3 , cif , y , p , q , r , nr , gasit , i, t , cod ;
int main()
{
    f >> a >> b >> c >> cod ;
    if ( cod == 1 )
    {
    //cele mai mari trei cifre ale lui b
    x = b ;
    max1 = -1 ;
    max2 = -1 ;
    max3 = -1 ;
    while ( x!=0 )
    {
        cif = x % 10 ;
        if ( cif >= max1 ) { t = max1 ; max1 = cif ; max3 = max2 ; max2 = t ;}
        else if ( cif >= max2 ) { max3 = max2 ; max2 = cif ; }
             else if ( cif >= max3 ) max3 = cif ;
        x = x / 10 ;
    }
    g << max3 << " " << max2 << " " << max1 ;
    }
    if ( cod == 2 )
    {
    //suma numerelor cuprinse intre a si b, divizibile cu c
    if ( a % c == 0 ) x = (a + c)/c ;
    else x =  a/c + 1 ;
    if ( b % c == 0 ) y = (b - c)/c ;
    else y =  b/c ;
    if ( x <= y ) g << c * ( y*(y+1)/2 - x*(x-1)/2) ;
    else g << 0 ;
    }
    if ( cod == 3 )
    {
    //cate numere cuprinse intre a si b au 3 cifre egale cu 1 in scrierea binara
    nr = 0 ;
    for ( p=1 ; p*7<b ; p=p*2 )
      for ( q=p*2 ; p+q<b ; q=q*2 )
        for ( r=q*2 ; p+q+r<b ; r=r*2 )
            if (( p+q+r>a)&&(p+q+r<b)) nr++ ;
    g << nr ;
    }
    if ( cod == 4 )
    {
    //numere ce au diferenta dintre produs si suma egala cu b
    gasit = 0 ;
    for( i=1 ; ((i*i<=(b+1))&&(gasit==0)) ; i++ )
      if (( (b+1)%i==0 )&&( i+1>a )&&( (b+1)/i+1<b)) gasit = 1 ;
    i-- ;
    if( gasit==1) g << i+1 << " " << (b+1)/i+1 ;
    else g<< 0 << " " << 0 ;
    }
    return 0;
}