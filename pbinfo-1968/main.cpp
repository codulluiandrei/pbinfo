//sol. Bunget Mihai
#include <fstream>
using namespace std;
ifstream f("bloc.in");
ofstream g("bloc.out");
long long k,p,n,nrcif,rest,grupe,suma,d,b,r,mc,s,m,c,a[101],u;
long long maxim,i,dir,inv,j,gr,t,sum[101],nr[101],nr1[101];
int main()
{
    f >> k >> p >> n ;
    //cerinta a)
    nrcif = (n+1)*p ;
    rest = nrcif % k ;
    grupe = nrcif / k ;
    suma = grupe * k * (k+1) / 2 + rest * (rest+1) / 2 ;
    g << suma << "\n" ;
    // cerinta b)
    d = k ;
    b = p ;
    r = d % b ;
    while ( r!=0 )
    {
        d = b ;
        b = r ;
        r = d % b ;
    }
    mc = (k*p)/b ;
    s = mc / p ;
    gr = ( n+1 ) / s ;
    rest = ( n+1 ) % s ;
    for ( i=1 ; i<=s ; i++ )
    {
        if ((s-i)%2==0)
           for ( j=1 ; j<=p ; j++ ) if ( (p*(i-1)+j)%k==0 ) a[j] += k ;
                                    else a[j] += (p*(i-1)+j)%k ;
        else
           for ( j=1 ; j<=p ; j++ ) if ( (p*(i-1)+j)%k==0 ) a[p+1-j] += k ;
                                    else a[p+1-j] += (p*(i-1)+j)%k ;
    }
    if ((gr*s+rest)%2==0)
       if (s%2==0) {dir=gr ; inv=0; }
       else if (gr%2==0) {dir=gr/2 ; inv=gr/2; }
            else { dir=gr/2 ; inv=(gr+1)/2; }
    else if (s%2==0){ dir=0 ; inv=gr; }
         else if (gr%2==0) {dir=gr/2 ; inv=gr/2; }
              else {dir=(gr+1)/2 ; inv=gr/2; }
    for (j=1 ; j<=p ; j++ ) sum[j]+=dir*a[j]+inv*a[p+1-j] ;
    for ( i=1 ; i<=rest ; i++ )
    {
        if ((rest-i)%2==0)
           for ( j=1 ; j<=p ; j++ ) { if ( (p*(i-1)+j)%k==0 ) sum[j] += k ;
                                      else sum[j] += (p*(i-1)+j)%k ;
                                    }
        else
           for ( j=1 ; j<=p ; j++ ) { if ( (p*(i-1)+j)%k==0 ) sum[p+1-j] += k ;
                                      else sum[p+1-j] += (p*(i-1)+j)%k ;
                                    }
    }
    maxim=0 ;
    for ( i=1 ; i<=p ; i++ )
       if ( sum[i]>maxim ) maxim = sum[i] ;
    g << maxim << "\n";
    //c
    if ( n<s)
    {
        if ( n%2==0)
        for ( i=1 ; i<=p ; i++ )
           if(i%k==0) nr[i]=k ;
           else nr[i]=i%k ;
        else
        for ( i=1 ; i<=p ; i++ )
           if(i%k==0) nr[p+1-i]=k ;
           else nr[p+1-i]=i%k ;
        for ( i=2 ; i<=n ; i++ )
       {
           if ((n-i+1)%2==0)
           {
             for ( j=1 ; j<=p ; j++ )
               if((p*(i-1)+j)%k==0) nr1[j]=k ;
               else nr1[j]=(p*(i-1)+j)%k ;
             u=1;
             while((nr[u]==nr1[u])and(u<p))u++ ;
             if (nr[u]>nr1[u])
                for ( j=1 ; j<=p ; j++ ) nr[j]=nr1[j] ;
           }
           else
           {
             for ( j=1 ; j<=p ; j++ )
               if((p*(i-1)+j)%k==0) nr1[p+1-j]=k ;
               else nr1[p+1-j]=(p*(i-1)+j)%k ;
             u=1;
             while((nr[u]==nr1[u])and(u<p))u++ ;
             if (nr[u]>nr1[u])
                for ( j=1 ; j<=p ; j++ ) nr[j]=nr1[j] ;
           }
       }
    }
    else
    {
       if ((n%2==0)or((n-s)%2==0))
       for ( i=1 ; i<=p ; i++ )
           if(i%k==0) nr[i]=k ;
           else nr[i]=i%k ;
       else
       for ( i=1 ; i<=p ; i++ )
           if(i%k==0) nr[p+1-i]=k ;
           else nr[p+1-i]=i%k ;
       for ( i=2 ; i<=s ; i++ )
       {
           if (((n-i+1)%2==0)or((n-i+1>=s)and((n-i+1-s)%2==0)))
           {
             for ( j=1 ; j<=p ; j++ )
               if((p*(i-1)+j)%k==0) nr1[j]=k ;
               else nr1[j]=(p*(i-1)+j)%k ;
             u=1;
             while((nr[u]==nr1[u])and(u<p))u++ ;
             if (nr[u]>nr1[u])
                for ( j=1 ; j<=p ; j++ ) nr[j]=nr1[j] ;
           }
           if (((n-i+1)%2==1)or((n-i+1>=s)and((n-i+1-s)%2==1)))
           {
             for ( j=1 ; j<=p ; j++ )
               if((p*(i-1)+j)%k==0) nr1[p+1-j]=k ;
               else nr1[p+1-j]=(p*(i-1)+j)%k ;
             u=1;
             while((nr[u]==nr1[u])and(u<p))u++ ;
             if (nr[u]>nr1[u])
                for ( j=1 ; j<=p ; j++ ) nr[j]=nr1[j] ;
           }
       }
    }
    for ( j=1 ; j<=p ; j++ ) g << nr[j] ;
    return 0;
}