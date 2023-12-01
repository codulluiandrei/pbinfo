//100p
#include "fstream"

std::ifstream cin("nevricos.in");
std::ofstream cout("nevricos.out");

long long Se, Ss, nr1, nr2;
int main(){
    char x, y;
    cin >> x;
    for(;cin >> y;){
        if(x == '1')
            ++ nr1;
        else if(x == '2')
            ++ nr2;

        if(y == '5'){
            Ss += nr1;
                if(x == '1')
                    ++ Se;
        }
        else if(y == '4'){
            Ss += nr2;
                if(x == '2')
                    ++ Se;
        }
        x = y;
    }
    cout<<Se<<'\n'<<Ss;
}