#include <fstream>
#include <iostream>

using namespace std;

void interclasare()
{
    ifstream fin1("file1.txt");
	ifstream fin2("file2.txt");
	ofstream fout("file.out");
    
    int n, m, x, y, i=1, j=1;
    fin1>>n; fin2>>m;
    fin1>>x; fin2>>y;
    while(i<=n && j<=m)
    {
        if(x<y) fout<<x<<' ', fin1>>x, ++i;
        else fout<<y<<' ', fin2>>y, ++j;
    }
    while(i<=n) fout<<x<<' ', fin1>>x, ++i;
    while(j<=m) fout<<y<<' ', fin2>>y, ++j;
}