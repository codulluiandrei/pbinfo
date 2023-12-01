/*
	Solutie 100 p cu ciur
	prof. Eugen Nodea
*/
# include <fstream>
# include <bitset>
# define N_Max 5000050
using namespace std;

ifstream f("pdigit.in");
ofstream g("pdigit.out");

bitset <N_Max+1> ciur;
int p[360001];
int s, k, n, c, i, a, b, nr, j, m, x, y, z;
void ciurerathos(int N)
{
    int i, j, M;
    p[1] = 1; N += 50;
    for(i=2; i<=N; ++i){
        if(ciur[i] == 0){
            p[++nr] = i; M = N / i;
            for(j=2; j<=M; ++j)
                ciur[i*j] = 1;
        }
    }
}

int cifracontrol(int a, int b)
{
    int z = a, s, P, x;
    while (z >= b) {
        ///calculam suma
        s = 0;
        while(z > 0){
            if (z % 10 >= b) return -1;
            s += z % 10;
            z /= 10;
        }
        ///trec numarul in baza b
        P = 1; x = 0;
        while(s>0) {
            x += (s % b) * P;
            P *= 10;
            s /= b;
        }
        z = x;
    }
    return z;
}
int main()
{
    f >> x >> y;
    
    ciurerathos( y );

    ///caut primul numar prim care are cifra de control = c >=a
    i = 1; j = nr;
    while(i <= j) {
        m = (i + j) >> 1;
        if (x <= p[m]) j = m - 1;
        		  else i = m + 1;
    }
    a = p[j + 1];
    g << a << "\n";

    ///determin baza b
    b = 0; z = a;
    while(z > 0){
        c = z % 10;
        if (c > b) b = c;
        z /= 10;
    }
    ++b;
    g << b << "\n";

    ///determin cifra de control
    c = cifracontrol(a, b);
    g << c << "\n";

    ///determin numerele prime din intervalul [x,y]
    i = j+2; k = 1;
    while (p[i] <= y) {
        if (cifracontrol(p[i], b) == c) ++k;
        ++i;
    }
    
    g << k << "\n";
    
    return 0;
}
