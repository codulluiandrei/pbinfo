/// solutie - Moca Andrei - 100p
#include <iostream>
using namespace std;
int main()
{
     int n, k;
     cin >> n >> k;
     if (k == 0)
     {
         cout << "1";
         for (int i = 2; i < n; i++)
            cout << "0";
         cout << "8";
         return 0;
     }
     if (k == 1)
     {
         cout << "1";
         for (int i = 2; i <= n; i++)
            cout << "0";
         return 0;
     }
     if (k == 2)
     {
         cout << "1";
         for (int i = 2; i < n; i++)
            cout << "0";
         cout << "1";
         return 0;
     }
     if (k == 3)
     {
         cout << "1";
         for (int i = 2; i < n; i++)
            cout << "0";
         cout << "2";
         return 0;
     }
     if (k == 4)
     {
         cout << "1";
         for (int i = 2; i < n; i++)
            cout << "0";
         cout << "3";
         return 0;
     }
     if (k == 5)
     {
         cout << "1";
         for (int i = 2; i < n; i++)
            cout << "0";
         cout << "4";
         return 0;
     }
     if (k == 6)
     {
         cout << "1";
         for (int i = 2; i < n; i++)
            cout << "0";
         cout << "5";
         return 0;
     }
     if (k == 7)
     {
         cout << "1";
         for (int i = 2; i < n; i++)
            cout << "0";
         cout << "6";
         return 0;
     }
     if (k == 8)
     {
         cout << "1";
         for (int i = 2; i < n; i++)
            cout << "0";
         cout << "7";
         return 0;
     }
}
