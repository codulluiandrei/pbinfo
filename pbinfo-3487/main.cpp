#include <iostream>
using namespace std;
long long ultimul_citit=0;
void citeste(long long anteriorul_citit){
    cin >> ultimul_citit;
    if (ultimul_citit >= anteriorul_citit) {citeste(ultimul_citit);}
    cout << anteriorul_citit << ' ';
}
int main()
{
    cin >> ultimul_citit;
    while (ultimul_citit!=0)
    {
        citeste(ultimul_citit);
    }
    return 0;
}