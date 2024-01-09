#include <fstream>
using namespace std;

int x[25] ,n;

ofstream fout("paranteze.out");

void afis(int n){
	for(int i=1;i<=n;++i)
		fout << (x[i]==0?'(':')');
	fout<<endl;
}

void back(int k, int deschise, int inchise){
	for(int i=0;i<2;++i){
		x[k] = i;
		if(i==0)
			deschise++;
		if(i==1)
			inchise++;
		if(inchise<=deschise)
			if(k==n){
				if(deschise==inchise)
					afis(n);
			}
			else
				back(k+1,deschise,inchise);
		if(i==0)
			deschise--;
		if(i==1)
			inchise--;
	}
}

int main(){
	ifstream fin("paranteze.in");
	fin>>n;
	fin.close();
	back(1,0,0);
	fout.close();
	return 0;
}
