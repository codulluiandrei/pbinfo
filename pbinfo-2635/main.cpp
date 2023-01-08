#include <bits/stdc++.h>
using namespace std;
ifstream in("capslock.in");
ofstream out("capslock.out");
char carac[300];
int main() {
    in.getline(carac, 300);
    for (int i = 0; i < strlen(carac); i++)
        if (carac[i] == '#') {
        int j = i + 1;
        while (carac[j] && carac[j] != '#') {
            carac[j] = toupper(carac[j]);
            j++;
        } i = j;
    }
    for (int i = 0; i < strlen(carac); i++)
        if (carac[i] != '#')
			out << carac[i];
	return 0;
}