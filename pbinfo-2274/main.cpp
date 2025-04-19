#include <fstream>
#include <limits.h>
using namespace std;
ifstream cin("limite.in");
ofstream cout("limite.out");
void type(unsigned long long int x){
    if(x <= SCHAR_MAX)
        cout << "char";
    else if(x <= UCHAR_MAX)
        cout << "unsigned char";
    else if(x <= SHRT_MAX)
        cout << "short";
    else if(x <= USHRT_MAX)
        cout << "unsigned short";
    else if(x <= INT_MAX)
        cout << "int";
    else if(x <= UINT_MAX)
        cout << "unsigned int";
    else if(x <= LONG_LONG_MAX)
        cout << "long long";
    else cout << "unsigned long long";
    cout << '\n';
}
int main()
{
    unsigned long long n,i,x;
    cin >> n;
    for(i = 1 ; i <= n ; ++i){
        cin >> x;
        type(x);
    }
    return 0;
}