#include <iostream>

using namespace std;

int main() {
    char a;
    int s=0, i=1;
    cin>>a; s+=(int)a;
    while(a!='.'){
        cin>>a;
        if (a=='.') break;
        else {s+=(int)a;
              i++;}
    }
    cout<<(char)(s/i);
    return 0;
}
