#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("secventauniforma.in");
ofstream fout("secventauniforma.out");
int main(){
	int x , y, lgmax = 0 , vmax, lg = 1;
    fin >> x;
    while(fin >> y)
    {
        if(x == y)
            lg ++;
        else
        {
            if(lg >= lgmax)
                lgmax = lg, vmax = x;
            lg = 1;
        }
        x = y;
    }
    if(lg >= lgmax)
        lgmax = lg, vmax = x;
    fout << lgmax << "\n";
    for(int i = 1 ; i <= lgmax ; i ++)
        fout << vmax << " ";
    fout << "\n";
    fin.close();
    fout.close();
    return 0;
}