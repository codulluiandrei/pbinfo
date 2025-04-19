#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a%2+b%2+c%2>=2)
        cout<<"impare";
    else
        cout<<"pare";
    return 0;
}