#include <iostream>
using namespace std;
int ndiv(int ogl)
{
    int S=0;
    for (int i=1; i*i <=ogl; ++i)
    {
        if (ogl%i ==0)
        {
            S=S+1;
            if (i*i <ogl)
            S=S+ 1;
        }
    }
    if (S % 2 == 0) return 0;
    else return 1;
}
 int happy(int a, int b)
 {
  int cmmdc;
  int r,ca,cb;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;

 }
 int main()
 {
     int n, a, b, x, maxi = -1, mini = 1000005;
     cin >> n;
     for (int i = 1; i <= n; i++)
     {
         cin >> a >> b;
         x = happy(a, b);
         if (x > maxi && ndiv(x) == 1) maxi = x;
         if (x < mini && ndiv(x) == 0) mini = x;
     }
     if (mini == 1000005 || maxi == -1) cout << "NU EXISTA";
     else cout << mini << " " << maxi;
 }

