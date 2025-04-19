# include <fstream>
using namespace std;
ifstream f("hanoi.in");
ofstream g("hanoi.out");
char a, b, c;
int n;
void Hanoi (int n, char a, char b, char c){
    if (n == 1) g << a << "->" << c << "\n";
    else {
        Hanoi(n-1, a, c, b);
        g << a << "->" << c << "\n";
        Hanoi(n-1, b, a, c);
    }
}
int main(){
    f >> n;
    g << (1 << n) - 1 << "\n";
    Hanoi(n, 'A', 'B', 'C');
    return 0;
}