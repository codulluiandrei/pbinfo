#include <iostream>
int main()
{
    int n=0, m=0;
    int a, b;
    while(std::cin>>a>>b)
    {
        m++;
        n=std::max(n, std::max(a, b));
    }
    std::cout<<2-n+m;
    return 0;
}