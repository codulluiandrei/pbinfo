#include <fstream>

using namespace std;
ifstream f("pxp.in");
ofstream g("pxp.out");

unsigned long long n,i,j,x,y,t,u,c[101],d[1000],q[1000],m,nr,z,e,k;
int a[1000001],b[1000001] ;
char v[1000001] ;

int main()
{
    f >> n >> e ;
    for ( i=0 ; i<=1000 ; i++ )
      for ( j=i ; j<=1000 ; j++ )
      {
          x = i*i + j*j ;
          if ( x<=1000000)
          {
              v[x] = 1 ;
              a[x] = i ;
              b[x] = j ;
          }
      }
    m = 0 ;
    nr = 0 ;
    for ( i=1 ; i<=n ; i++ )
    {
        f >> x ;
        if ( v[x]==1 )
        {
            nr++ ;
            if ( x!=1 )
            {
               m++ ;
               c[m] = x ;
            }
        }
    }
    if ( nr > m ) { m++ ; c[m] = 1 ;} ;

    x = a[c[1]] ;
    y = b[c[1]] ;
    for ( i=2 ; i<=m ; i++ )
    {
        t = x*a[c[i]]+y*b[c[i]] ;
        if ( x*b[c[i]]>y*a[c[i]]) u = x*b[c[i]]-y*a[c[i]] ;
        else u = y*a[c[i]]-x*b[c[i]] ;
        x = t ;
        y = u ;
    }
    g << nr << "\n" ;
    if ( e==1 )
    {
        g << x << " " << y ;
    }
    if ( e==2 )
    {
        if ( x<y ){ t=x ; x=y ; y=t; }
        t = x-y ;
        u = x+y ;
        m = 0 ;
        while(t!=0)
        {
            m++ ;
            c[m] = t%10 ;
            t = t / 10 ;
        }
        t = 0 ;
        for ( i=1 ; i<=m ; i++ )
        {
           z = c[i] * u + t ;
           c[i] = z % 10 ;
           t = z / 10 ;
        }
        if ( t>0 ) g << t ;
        for ( i=m ; i>=1 ; i-- ) g << c[i] ;
        g << " " ;
        t = 2 * x ;
        u = y ;
        m = 0 ;
        while(t!=0)
        {
            m++ ;
            c[m] = t % 10 ;
            t = t / 10 ;
        }
        t = 0 ;
        for ( i=1 ; i<=m ; i++ )
        {
           z = c[i] * u + t ;
           c[i] = z % 10 ;
           t = z / 10 ;
        }
        if ( t>0 ) g << t ;
        for ( i=m ; i>=1 ; i-- ) g << c[i] ;

    }
    if ( e==3 )
    {
        d[1] = 1 ;
        i = 1 ;
        for( j=1 ; j<=m ; j++ )
        {
            t = 0 ;
            for( k=1 ; k<=i ; k++ )
            {
                z = c[j] * d[k] + t ;
                d[k] = z % 10 ;
                t = z / 10 ;
            }
            while (t>0){i++ ; d[i]=t%10 ; t=t/10;}
        }
        t = 0 ;
        for ( j=1 ; j<=i ; j++ )
        {
            z = d[j] * x + t ;
            q[j] = z % 10 ;
            t = z / 10 ;
        }
        if ( t>0 ) g << t ;
        for( j=i ; j>=1 ; j-- ) g << q[j] ;
        g << " " ;
        t = 0 ;
        for ( j=1 ; j<=i ; j++ )
        {
            z = d[j] * y + t ;
            q[j] = z % 10 ;
            t = z / 10 ;
        }
        if ( t>0 ) g << t ;
        for( j=i ; j>=1 ; j-- ) g << q[j] ;
    }
    return 0;
}
