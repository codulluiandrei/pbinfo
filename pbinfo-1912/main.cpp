// sursa 100 Gotca Adrian
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("becuri.in");
ofstream fout("becuri.out");
int n;
int main(){
    fin>>n;
    fout<<(int)sqrt(n);
    return 0;
}