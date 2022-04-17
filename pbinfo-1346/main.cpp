#include <fstream>
#include <string.h>
using namespace std;
ifstream in("pbinfo.in");
ofstream out("pbinfo.out");
int main() {
    char link[101], cuv[100][103];
    int var, temp = 0;
    in.get();
    in.get(link, 101);
    in >> var;
    while (var != 0) {
        in.get();
        in.get(cuv[temp], 103);
        temp++;
        var--;
    } if (strstr(link, "virus")) out << "DA";
    else {
        bool adv =  false;
        for (int i = 0; i < temp; i++) {
            if (strstr(link, cuv[i])) {
                adv = true;
                break;
			}
        } if (adv == true) out << "DA";
        else out << "NU";
    } return 0;
}