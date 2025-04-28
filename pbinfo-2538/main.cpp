/* ***************************
   *  Solutie Oficiala 100p  *
   *  Vintila Valentin Ioan  *
   *************************** */
//  A se citi indicatiile problemei
//  pentru ca aceasta sursa sa aiba
//  sens!
#include <iostream>
using namespace std;
int main()
{
    long long xA, yA, xB, yB, xC, yC, i2, j2;
    long long Dpa, Dpb, Dpc, xP, yP;
    cin >> xA >> yA >> xB >> yB >> xC >> yC;
    cin >> Dpa >> Dpb >> Dpc;
    i2 = Dpa - Dpc - xA*xA + xC*xC - yA*yA + yC*yC;
    j2 = Dpb - Dpc - xB*xB + xC*xC - yB*yB + yC*yC;
    xP = (i2*(yC-yB) - j2*(yC-yA)) /
         (2 * ((xC-xA)*(yC-yB) - (xC-xB)*(yC-yA)));
    yP = (i2*(xC-xB) - j2*(xC-xA)) /
         (2 * ((yC-yA)*(xC-xB) - (yC-yB)*(xC-xA)));
    cout << xP << ' ' << yP;
}
//  Nota: i2 = 2 * i (am explicat in indicatii)
//        j2 = 2 * j