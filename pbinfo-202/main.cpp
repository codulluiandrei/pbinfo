#include <fstream>
using namespace std;
int x[10] ,n;
ofstream fout("permpf.out");
int OK(int k){
	if(x[k]==k)
		return 0;
	for(int i=1;i<k;++i)
		if(x[k]==x[i])
			return 0;
	return 1;
}
void back(int k){
	for(int i=1 ; i<=n ; ++i)
	{
		x[k]=i;
		if( OK(k) )
			if(k==n){
				for( int j=1;j<=n;j++)
					fout<<x[j]<<" ";
				fout<<endl;
			}
			else
				back(k+1);
	}
}
int main(){
	ifstream fin("permpf.in");
	fin>>n;
	fin.close();
	back(1);
	fout.close();
	return 0;
}