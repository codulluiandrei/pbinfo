#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("puteri6.in");
ofstream fout("puteri6.out");

int v[10];

int main(){
	int x , n;
    fin >> n;
    while(fin >> x)
    {
        int p = 0;
        while(x > 1)
            p++, x /=10;
        v[p] ++;
    }
    int p = 0, s = 0;
    while(p < 10 && s + v[p] < n)
        s += v[p], p ++;
    if(p < 10)
    {
        x = 1;
        while(p)
            x *= 10, p --;
        fout << x << endl;
    }
    else
        fout << "Nu exista
";
    fin.close();
    fout.close();
    return 0;
}
