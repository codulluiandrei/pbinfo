#include <iostream>
#include <cstdlib>
using namespace std;
int n , x[20];
bool gasit = false;
bool Valid(int k)
{
    for(int i = 1 ; i < k ; i ++)
    {
        if(x[i] == x[k])
            return false;
        if(k - i == abs(x[k] - x[i]))
            return false;
    }
    return true;
}
void Afisare(int n)
{
    gasit = true;
    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j = 1 ; j <= n ; j ++)
            if(x[j] == i)
                cout << "* ";
            else
                cout << "- ";
        cout << endl;
    }
}
void Back(int k)
{
    //std :: cout << k << " ";
    for(int i = 1 ; !gasit && i <= n ; i ++)
    {
        x[k] = i;
        if(Valid(k))
            if(k == n)
                Afisare(n);
            else
                Back(k + 1);
    }
    //std :: cout << '\n';
}
int main()
{
    cin >> n;
    Back(1);
    return 0;
}