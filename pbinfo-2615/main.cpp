//C++11
#include <fstream>
#include <string>   //biblioteca specifica C++ pentru a lucra cu string-uri. A nu se confunda cu <cstring>.
using File = std::fstream;  //creem un alias
File in, out;   //declaram stream-urile
std::string textin, op, textout;
int n;
int main()
{
    in.open("caesar.in", File::in);                     //deschidem stream-ul de intrare.
    out.open("dbftbs.out", File::out | File::trunc);    //deschidem stream-ul de iesire.
    std::getline(in, textin);   //citim prima textul.
	in>>n>>op;                  //citim numarul si operatia.
    n%=26; //26 caractere in alfabetul englez.
	if(op=="encrypt")
    {
        for(char c : textin)    //structura for_each din C++11. Inlocuieste for(int i=0; i<textin.size(); i++){...textin[i]...}. A nu se confunda cu std::for_each din <algorithm>.
        {
            if(std::isspace(c) || !std::isalpha(c)) textout+=c; //verificam daca e litera.
            else if(std::isupper(c)) textout+=(char)(((int)(c)+n-65)%26+65);        //
            else textout+=(char)(((int)(c)+n-97)%26+97);                            // convertim caracterul.
        }
    }
    if(op=="decrypt")
    {
        for(char c : textin)    //structura for_each din C++11. Inlocuieste for(int i=0; i<textin.size(); i++){...textin[i]...}. A nu se confunda cu std::for_each din <algorithm>.
        {
            if(std::isspace(c) || !std::isalpha(c)) textout+=c; //verificam daca e litera.
            else if(std::isupper(c)) textout+=(char)(((int)(c)-65+26-n)%26+65);     //
            else textout+=(char)(((int)(c)-97+26-n)%26+97);                         //aplicam acceasi operatie ca si la encrypt iar 'n' devine '26-n'.
        }
    }
    out<<textout;   //afisam textul prelucrat
    return 0;
}