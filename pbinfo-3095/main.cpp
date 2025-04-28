#include <iostream>
using namespace std;
unsigned long long nr;
char c[20];
void baza16(int i)
{
    if(c[i] != NULL)
    {
        if(c[i] >= '0' && c[i] <= '9')
          nr = nr * 16 + c[i] -'0';
        if(c[i] >= 'A' && c[i] <= 'F')
          nr = nr * 16 + 10 + c[i]- 'A';
        baza16(i+1);
    }
    return;
}
int main()
{
    cin.getline(c, sizeof(c));
    baza16(0);
    cout << nr;
    return 0;
}