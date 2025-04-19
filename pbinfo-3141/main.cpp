/// Sursa Vasiluta Mihai-Alexandru
#include <fstream>
using namespace std;
ifstream f("atbash.in");
ofstream g("atbash.out");
char c;
int main()
{
    while(f >> c)
        g << char('Z' - c + 'A');
    return 0;
}