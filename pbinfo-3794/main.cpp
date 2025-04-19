#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    /// luam cele2 siruri si le punem in 2 fisiere diferite
    ifstream fin("file.in");
 	ofstream fout1("file1.txt");
  	ofstream fout2("file2.txt");
  	int n, m, x;
  	fin>>n>>m;
  	for(int i=1;i<=n;++i)
      	fin>>x,
  		fout1<<x<<' ';
  	for(int i=1;i<=m;++i)
      	fin>>x,
  		fout2<<x<<' ';
  	fin.close();
  	fout1.close();
  	fout2.close();
  	/// aplicam interclasarea
  	ifstream fin1("file1.txt");
    ifstream fin2("file2.txt");
    ofstream fout("file.out");
  	int y, i=1, j=1;
    fin1>>x; fin2>>y;
    while(i<=n && j<=m)
    {
        if(x<y) fout<<x<<' ', fin1>>x, ++i;
        else fout<<y<<' ', fin2>>y, ++j;
    }
    while(i<=n) fout<<x<<' ', fin1>>x, ++i;
    while(j<=m) fout<<y<<' ', fin2>>y, ++j;
  	return 0;
}