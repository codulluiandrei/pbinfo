#include <fstream>
#include <cstring>
#include <iostream>
std::ifstream fin("siruri_concatenate.in");
std::ofstream fout("siruri_concatenate.out");
char cuvant[5000];
bool concatenat() {
    int lungime = strlen(cuvant);
    if(lungime % 2)
        return 0;
    for(int i = 0; i < lungime / 2; i++)
        if(cuvant[i] != cuvant[i + lungime / 2])
            return 0;
    return 1;
}
int main() {
    int nr_siruri, concatenate = 0;
    fin >> nr_siruri;
    for(int i = 1; i <= nr_siruri; i++)
    {
        fin >> cuvant;
        concatenate += concatenat();
    }
    fout << concatenate;
	return 0;
}