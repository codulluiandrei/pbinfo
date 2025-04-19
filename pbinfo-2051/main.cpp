/*
    prof. Ionel Vasile Pit-Rada
    Complexitate O(N + T)
*/
#include<fstream>
using namespace std;
int c, n, m, a[100005], st[100005], f[100005], b[100005], T, p, q, t, i, x, y, max1, max2, k, z;
long long sp[100005],v,nr;
void sol1(){
    ifstream  fin("pp.in");
    ofstream fout("pp.out");
	fin>>c;
	if(c==1){
		fin>>n;
		v=0;
		for(i=1;i<=n;i++){
			fin>>a[i];
			v=v+a[i];
			sp[i]=v;
		}
		fin>>T;
		for(t=1;t<=T;t++){
			fin>>p>>q;
			fout<<sp[q]-sp[p-1]<<'\n';
		}
	}
	if(c==2){
		fin>>n; m=0;
		for(i=1;i<=n;i++){
			fin>>a[i];
			if(f[a[i]]==0){
				v=f[a[i-1]];
				sp[m]=sp[m-1]+v*(v-1)/2;
				m++; st[m]=i;
			}
			f[a[i]]++;
			b[i]=m;
		}
		v=f[a[n]];
		sp[m]=sp[m-1]+v*(v-1)/2;
		st[m+1]=n+1;
		fin>>T;
		for(t=1;t<=T;t++){
			fin>>p>>q;
			x=b[p]; y=b[q];
			nr=(long long)(q-p+1)*(q-p)/2;
			v=sp[y-1]-sp[x]+(long long)(q-st[y]+1)*(q-st[y])/2+(long long)(st[x+1]-p)*(st[x+1]-p-1)/2;
			nr=nr-v;
			fout<<nr<<'\n';
		}
	}
    fin.close();
    fout.close();
}
int main(){
    sol1();
    return 0;
}