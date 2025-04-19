#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("progresie3.in");
ofstream fout("progresie3.out");
int v[1001];
int main(){
	int x, y, r, ok = 1;
    while(fin >> x)
        v[x] = 1;
    x = 0;
    while(v[x] == 0)
        x ++;
    y = x + 1;
    while(v[y] == 0)
        y ++;
    r = y - x;
    x= y;
    for(int i = y + 1; i <= 1000 ; i ++)
        if(v[i] == 1)
        {
            if(i - x != r)
                ok = 0;
            x = i;
        }
    if(ok)
        fout << r;
    else
        fout << "NU";
	return 0;
}