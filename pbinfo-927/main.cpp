#include <fstream>
using namespace std;
ifstream fin("distantapuncte.in");
ofstream fout("distantapuncte.out");
int X1, Y1, X2, Y2;
int main() {
    fin>>X1>>Y1>>X2>>Y2;
    fout<<(X1-X2)*(X1-X2) + (Y1-Y2)*(Y1-Y2)<<"\n";
    return 0;
}