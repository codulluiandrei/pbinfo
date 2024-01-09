#include <iostream>
using namespace std;

char baza[]="0123456789ABCDEF";
void generare (unsigned int n , int p)
{
    if(n)
    {
       generare(n / 16 , p * 16); 
       cout << baza[n%16];
    }
}

int main()
{
    unsigned int n;
    cin >> n;
    generare(n,1);
    return 0;
}