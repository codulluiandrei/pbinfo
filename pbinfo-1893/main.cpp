#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
long a,b,c ;

int main()
{
    srand (time(NULL));
    a = rand()%21623+10000;
    b = rand()%21623+10000;
    c = a*b ;
    cout << c ;
    return 0;
}
