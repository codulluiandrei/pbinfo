#include <fstream>
#include <cstring>
using namespace std;
char sir1[256], sir2[256];
int cod[256];
ifstream in("vigenere.in");
ofstream out("vigenere.out");
int main(){
    in.getline(sir1, 256);
    in.getline(sir2, 256);
    int n = strlen(sir1), k = strlen(sir2);
    for(int i = 0; i < k; i++){
        cod[i] = sir2[i] - 'a';
    }
    for(int i = 0; i < n; ){
        for(int j = 0; j < k && i < n; i++, j++){
            sir1[i] = (sir1[i] - 'a' + cod[j]) % 26 + 'a';
        }
    }
    out << sir1;
}