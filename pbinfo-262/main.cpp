#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
ifstream fin("intervale1.in");
ofstream fout("intervale1.out");
int main(){
	int n,a,b,rez = 1000000000;
	fin >> n;
	double x,y;
	fin >> x;
	for(int i=2;i<=n;++i)
	{
		assert(fin >> y);
		if(x>=y)
			cout << fixed <<  x << " " << y << endl;
        //a = cel mai mic numar intreg, mai mare decat x
        if(x > 0)
            a = int(x)+1;
        else
        {
            a = int(x);
            if(a == x)
                a ++;
        }
        //b = cel mai mare numar intreg, mai mic decat y
        if(y < 0)
            b = (int) y -1;
        else
        {
            b = (int)y;
            if(b == y)
                b--;
        }
		if(b-a+1<rez)
			rez = b-a+1;// cout << fixed <<  x << " " << y << endl;
		x = y;
	}
	fout << rez << "\n";
	return 0;
}