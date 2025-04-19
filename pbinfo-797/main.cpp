#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("subnumar.in");
ofstream fout("subnumar.out");
int v[100];
int main(){
	int x;
	while(fin >>x)
		while(x >= 10)
			v[x % 100] ++ , x /= 10;
	int Max = -1;
	for(int i = 10 ; i <= 99 ; i ++)
		if(v[i] > Max)
			Max = v[i];
	for(int i = 99 ; i > 9 ; i --)
		if(v[i] == Max)
			fout << i << " ";
	return 0;
}