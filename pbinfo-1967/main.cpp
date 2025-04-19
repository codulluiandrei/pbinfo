//sol.Bunget Mihai
#include <fstream>
using namespace std;
ifstream f("cmmdc0.in");
ofstream g("cmmdc0.out");
int n,i,ok,m,i2,i3,i5,i7,x,y,r,minim,a[6000],b[6000],d[6000];
int main()
{
    f >> n ;
    for ( i=1 ; i<=n ; i++ ) f >> a[i] >> d[i] ;
    ok = 1 ;
    b[1] = 1 ;
    m = 1 ;
    i2 = 1; i3 = 1 ; i5 = 1 ; i7 = 1 ;
    while ( ok )
    {
       ok = 0 ;
       for ( i=1 ; i<=n ; i++)
       {
           x = a[i] ;
           y = b[m] ;
           r = x % y ;
           while ( r!=0 )
           {
               x = y ;
               y = r ;
               r = x % y ;
           }
           if (y!=d[i]){ ok = 1 ;break ; }
       }
       if (ok)
       {
           minim = b[i2] * 2 ;
           if (b[i3]*3<minim) minim = b[i3] * 3 ;
           if ( b[i5]*5 < minim) minim = b[i5] * 5 ;
           if ( b[i7]*7 < minim) minim = b[i7] * 7 ;
           m++ ;
           b[m] = minim ;
           if (b[i2]*2==minim) i2++ ;
           if (b[i3]*3==minim) i3++ ;
           if (b[i5]*5==minim) i5++ ;
           if (b[i7]*7==minim) i7++ ;
       }
    }
    g << b[m] ;
    return 0;
}