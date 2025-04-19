#include <iostream>
using namespace std;
int main()
{
   int n , m , i , f[501][501] , t=0 , j , sum , ok , ok2 , h , copie ;
   cin >> n >> m ;
   for(i=1; i<=n; i++)
   {
       for(j=1; j<=m; j++)
       {
           cin >> f[i][j] ;
       }
   }
   for(i=1; i<=n; i++)
   {
       for(j=1; j<=m; j++)
       {
           t++ ;
           copie=f[i][j] ;
           ok=1 ;
           if(copie == 1 || copie == 0)
           {
                 ok=0 ;
           }
           else{
                  for(h=2; h*h<=copie; h++)
                  {
                        if(copie % h*h == 0){ok=0; }
                  }
           }
           ok2=1;
           sum=0;
           while(copie != 0)
           {
                 sum+=copie%10 ;
                 copie/=10 ;
           }
           if(sum==1 || sum==0){ok2=0 ; }
           else{
            for(h=2; h*h<=sum; h++)
            {
                  if(sum%h*h==0){ok2=0 ; }
            }
           }
              if(ok == 1)
             {
                 if(i==1 && j==1)
                 {
                     f[i][j]=0;
                 }
                 else{
                    t++ ;
               f[i][j]=0 ;
               if(i > 1){i-- ;}
               if(j > 1){j-- ;}
                 }
             }
           else if(ok2 == 1)
           {
                if(i==n && j==m)
            {
            f[i][j]=0;
            }
            else{
            t++ ;
               f[i][j]=0;
               if(i < n){i++ ;}
               if(j < m){j++ ;}
             }
           }
       }
   }
   cout << t ;
    return 0;
}