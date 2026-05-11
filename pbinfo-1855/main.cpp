#include <iostream>
#include <fstream>
using namespace std;
fstream fin, fout;
int H[250005], n , m , op, k;
void Promovare(int k)
{
    bool esteHeap = false;
    while(k > 1 && !  esteHeap)
    {
        if(H[k] <= H[k/2])
            esteHeap = 1;
        else
        {
            int aux = H[k]; H[k] = H[k/2] ; H[k/2] = aux;
            k /= 2;
        }
    }
}
void Cernere(int k)
{
    bool esteHeap = false;
    while(2 * k <= n && !esteHeap){
        int p = 2 * k;
        if(p + 1 <= n && H[p] < H[p+1])
            p ++;
        if(H[k] >= H[p])
            esteHeap = true;
        else
        {
            int aux = H[k]; H[k] = H[p]; H[p] = aux;
            k = p;
        }
    }
}
int main(){
    fin.open("heap.in", ios::in);
    fout.open("heap.out", ios::out);
    fin >> m;
    n = 0;
    for ( ; m ; m --)
    {
        fin >> op;
        if(op == 1)
        {
            fin >> k;
            H[++n] = k;
            Promovare(n);
        }
        else
        {
            fout << H[1] << "\n";
            H[1] = H[n--];
            Cernere(1);
        }
    }
    fin.close() ,fout.close();
    return 0;
}