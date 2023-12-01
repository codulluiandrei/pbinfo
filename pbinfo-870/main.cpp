#include <iostream>
using namespace std;

struct mutare{char X,Y;};

int nA , A[1005] , nB , B[1005] , nC , C[1005] , nrm;
mutare mutari[2005];

int main()
{
	int n;
	cin >> n;
	nA = n;
	for(int i = 1 ; i <= nA ; i ++)
			cin >> A[i];
	for(int i = 1 ; i <= n ; i ++)
		if(B[nB] == i)
		{
			C[++nC] = i, nB --;
			nrm ++;
			mutari[nrm].X = 'B', mutari[nrm].Y = 'C';
			//cout << mutari[nrm].X << " " << mutari[nrm].Y << " " << i << endl;
		}
		else
		{
			bool gasit = false;
			while(nA > 0 && !gasit)
				if(A[nA] == i)
				{
					C[++nC] = i, nA --;
					nrm ++;
					mutari[nrm].X = 'A', mutari[nrm].Y = 'C';
					//cout << mutari[nrm].X << " " << mutari[nrm].Y << " " << i << endl;
					gasit = true;
				}
				else					
				{
					B[++nB] = A[nA], nA --;
					nrm ++;
					mutari[nrm].X = 'A', mutari[nrm].Y = 'B';
					//cout << mutari[nrm].X << " " << mutari[nrm].Y << " " << A[nA+1] << endl;
				}
			if(!gasit)
			{
				cout << 0;
				return 0;
			}
		}
	cout << nrm << "\n";
	for(int i = 1 ; i <= nrm ; i ++)
		cout << mutari[i].X << " " << mutari[i].Y << "\n";
	return 0;
}
