#include <fstream>
#include <cstring>
using namespace std;
ifstream in("cnp.in");
ofstream out("cnp.out");
bool verifcif(char L) {
    if (L >= '0' && L <= '9')
        return true;
    return false;
}
int main() {
    char s[210], t[210];
    bool adv = false;
    while (in.getline(s, 210))
        for (long long int i = 0; i < strlen(s); i++)
        	if (verifcif(s[i])) {
                int j = i + 1;
                while (verifcif(s[j])) j++;
                if (j - i == 13) {
                    strcpy(t, s + i);
                    t[13] = 0;
                    out << t << "\n";
                    adv = true;
                }
				i = j - 1;
    		}
    if (adv == false) out << 0;
    return 0;
}