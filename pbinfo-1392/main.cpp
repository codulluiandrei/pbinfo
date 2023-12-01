#include <fstream>

using namespace std;
ifstream f("sumo.in");
ofstream g("sumo.out");
long long n , i , p , q , t , e , j , nr1 , nr2 , res1 , res2 , sol , sol1 , sol2 , k , m , cif , nr , r , c , a ;

int main()
{
    f >> n ;
    for ( i=1 ;i<=n ;i++ )
    {
        f >> p >> q ;

        t=0 ;
        e=1 ;
        j=0 ;
        while ( t<=p )
        {
            j++ ;
            t = t + 9*e*j ;
            e = e*10 ;
        }
        e = e/10 ;
        t = t - 9*e*j ;
        p = p - t ;
        if(p==0)j--;
        nr1 = e + p/j -1 ;
        res1 = p%j ;
        if ( res1==0 ) { nr1-- ; res1=j ; }

        t=0 ;
        e=1 ;
        j=0 ;
        while ( t<=q )
        {
            j++ ;
            t = t + 9*e*j ;
            e=e*10 ;
        }
        e = e/10 ;
        t = t - 9*e*j ;
        q = q - t ;
        if(q==0)j--;
        nr2 = e + q/j -1 ;
        res2 = q%j ;


        sol1 = 0 ;
        for ( c=1 ; c<=9 ; c++ )
        {
           sol = 0 ;
           m = nr1 ;
           p = 10 ;
           nr = 0 ;
           while(m!=0){nr++;m=m/10;}
           for(j=1;j<=nr;j++)
            {
               r=nr1%p;a=nr1/p;cif=r/(p/10);
               if(cif>c)sol=sol+(a+1)*(p/10);
               else if(cif==c)sol=sol+a*(p/10)+r%(p/10)+1;
                    else sol=sol+a*(p/10);
               p=p*10;
            }
        sol1 = sol1 + sol*c ;
        }

        sol2 = 0 ;
        for ( c=1 ; c<=9 ; c++ )
        {
           sol = 0 ;
           m = nr2 ;
           p = 10 ;
           nr = 0 ;
           while(m!=0){nr++;m=m/10;}
           for(j=1;j<=nr;j++)
            {
               r=nr2%p;a=nr2/p;cif=r/(p/10);
               if(cif>c)sol=sol+(a+1)*(p/10);
               else if(cif==c)sol=sol+a*(p/10)+r%(p/10)+1;
                    else sol=sol+a*(p/10);
               p=p*10;
            }
        sol2 = sol2 + sol*c ;
        }

        sol = sol2 - sol1 ;

        if ( res1!=0 )
        {
        nr1++ ;
        a = nr1 ;
        j = 0 ;
        while (a!=0)
        {
            j++ ;
            a = a/10 ;
        }
        a = nr1 ;
        k = 0 ;
        while (a!=0)
        {
            k++ ;
            r = a%10 ;
            if ( k>j-res1+1 ) sol = sol - r ;
            a = a/10 ;
        }
        }
        if ( res2!=0 )
        {
        nr2++ ;
        a = nr2 ;
        j = 0 ;
        while (a!=0)
        {
            j++ ;
            a = a/10 ;
        }
        a = nr2 ;
        k = 0 ;
        while (a!=0)
        {
            k++ ;
            r = a%10 ;
            if ( k>j-res2 ) sol = sol + r ;
            a = a/10 ;
        }
        }
        g << sol <<"\n" ;

    }

    return 0;
}
