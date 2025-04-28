//Afisare folosind o functie.
#include <fstream>
#include <string>
using File = std::fstream;
File in, out;
void CharBitPrint(char c)
{
    for(int i=7; i>=0; i--) out<<((c>>i)&1);
    out<<' ';
}
std::string text, key;
char xored;
int main()
{
	in.open("xorcrypt.in", File::in);
	out.open("xorcrypt.out", File::out | File::trunc);
    std::getline(in, text);
    std::getline(in, key);
    for(std::string::size_type i=0; i<text.size(); i++)
    {
        xored=text[i]^key[i];
        CharBitPrint(xored);
    }
    return 0;
}