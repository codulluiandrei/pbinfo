//100 p
#include "fstream"
std::ifstream cin("caraghios.in");
std::ofstream cout("caraghios.out");
int nr;
int main(){
    char x, y;
    cin >> x;
    if(x == '1')
        ++ nr;
    for(;cin >> y;){
        if(y == '1'){
            ++ nr;
            if(x == '8')
                ++ nr;
        }
        x = y;
    }
    cout<<nr;
}