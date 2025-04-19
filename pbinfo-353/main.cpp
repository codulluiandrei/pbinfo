#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("spectacole.in");
ofstream fout("spectacole.out");
struct spectacol{
	int start,stop;
};
int n;
spectacol V[105];
bool MaiMic(spectacol x, spectacol y){
	if(x.stop >= y.stop)
		return false;
	return true;
}
void Sortare(){
	for(int i=0 ; i<n-1 ; i++)
		for(int j=i+1 ; j<n ; ++j)
			if(MaiMic(V[j],V[i])){
				spectacol Aux = V[i];
				V[i] = V[j];
				V[j] = Aux;
			}
}
int main(){
	fin >> n;
	for(int i=0;i<n;++i)
		fin >> V[i].start >> V[i].stop;
	Sortare();
	int rez = 1;
	int i=0 , j=0;
	while(i<n)
	{
		j = i+1;
		while(V[j].start<V[i].stop && j<n)
			j++;
		if(j<n)
			rez ++;
		i = j;
	}
	fout << rez;
	return 0;
}