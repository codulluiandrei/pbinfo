#include <fstream>
using namespace std;
int x[10] ,n, poz[10];
int nrsol=0;
ofstream fout("shuffle.out");
int Vecine(int a,int b){
	if(poz[a]-poz[b]==1 || poz[a]-poz[b]==-1)
		return 1;
	return 0;
}
int OK(int k){
	if(k==1)
		return 1;
	for(int i=1;i<k;++i)
		if(x[k]==x[i])
			return 0;
	if(Vecine(x[k],x[k-1]))
		return 0;
	return 1;
}
void back(int k){
	for(int i=1 ; i<=n ; ++i)
	{
		x[k]=i;
		if( OK(k) )
			if(k==n){
				nrsol++;
				for( int j=1;j<=n;j++)
					fout<<x[j]<<" ";
				fout<<endl;
			}
			else
				back(k+1);
	}
}
int main(){
	ifstream fin("shuffle.in");
	fin>>n;
	for(int i=1;i<=n;++i){
		int x;
		fin >> x;
		poz[x] = i;
	}
	fin.close();
	back(1);
	if(nrsol == 0)
		fout << "nu exista";
	fout.close();
	return 0;
}