#include <iostream>
using namespace std;
int main()
{
    int v[50] = {0}, len = 0;
    int n;
    cin >> n;
    do
    {
        v[len++] = n % 3;
        n /= 3;
    }
    while(n > 0);
    for(int i = 0; i < len; ++i){
        if(v[i] > 1)
        {
            v[i] -= 3;
            v[i + 1]++;
        }
    }
    if(v[len] == 1)
        len++; //verificam daca s-a adaugat o cifra noua
    for(int i = len - 1; i >= 0; --i)
    {
        if(v[i] == -1)
            cout << "T";
        else
            cout << v[i];
    }
    return 0;
}