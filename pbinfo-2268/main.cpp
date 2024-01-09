#include <iostream>
#include <map>
#include <cassert>

using namespace std;

int main()
{
    int n;
    map<string , int> M;
    for(cin >> n ; n ; -- n)
    {
        string S;
        assert(cin >> S);
        M[S] ++;
    }
    pair<string , int> Rez = {"", 0};
    for(auto x : M)
        if(x.second > Rez.second)
            Rez = x;
        else
            if(x.second == Rez.second)
                if(x.first < Rez.first)
                    Rez = x;
    cout << Rez.first << " " << Rez.second << "
";
    return 0;
}
