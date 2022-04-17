#include <bits/stdc++.h>
using namespace std;

ifstream in("parcare.in");
ofstream out("parcare.out");

int main() {
    int zzint, llint, hhint, mmint;
    in >> zzint >> llint >> hhint >> mmint;
    int zzple, llple, hhple, mmple;
    in >> zzple >> llple >> hhple >> mmple;
    int taxa, cer;
    in >> taxa >> cer;
    int afis1, afis2, afis3, temp1, temp2, taxa1;
    if (abs(mmint - mmple) == 1 && cer == 2) out << 0;
    else {
        if (mmint > mmple) {
            afis3 = 60 - mmint + mmple;
            hhint++;
        } else afis3 = mmple - mmint;
        if (hhint > hhple) {
            afis2 = 24 - hhint + hhple;
            zzint++;
        } else afis2 = hhple - hhint;
        if (llint == 2 && zzint > 21 && zzint > zzple) afis1 = 28 - zzint + zzple;
        if (llint == 8 && zzint > 24 && zzint > zzple) afis1 = 31 - zzint + zzple;
        if (llint % 2 == 1 && llint < 8 && zzint > 24 && zzint > zzple) afis1 = 31 - zzint + zzple;
        if (llint % 2 == 0 && llint > 8 && zzint > 24 && zzint > zzple) afis1 = 31 - zzint + zzple;
        if (llint % 2 == 0 && llint != 2 && llint < 8 && zzint > 23 && zzint > zzple) afis1 = 30 - zzint + zzple;
        if (llint % 2 == 1 && llint > 8 && zzint > 23 && zzint > zzple) afis1 = 30 - zzint + zzple;
        if (zzint <= zzple) afis1 = zzple - zzint;
        temp1 = afis1 * 24;
        temp2 = (temp1 + afis2) * 60 + afis3;
        if (afis1 == 0 && afis2 == 0 && afis3 <= 15) taxa1 = 0;
        if (temp2 % 60 == 0) taxa1 = temp2 / 60 * taxa;
        else taxa1 = (temp2 / 60 + 1) * taxa;
        if (cer == 1) out << temp2;
        else out << taxa1;
    }
    return 0;
}