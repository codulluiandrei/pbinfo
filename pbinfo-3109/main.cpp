#include <bits/stdc++.h>
/// Implementation : Adrian Panaete
using namespace std;
ifstream f("tunel.in");
ofstream g("tunel.out");
const int maxTunnelLength = 50002;
int speed[maxTunnelLength];
int
numberOfCars,numberOfGroups,
tunnelLength,
carPosition,carDistance,carSpeed,
groupSpeed,groupDistance,
groupSize,maxSize;
int main()
{
    f>>numberOfCars>>tunnelLength;
    for(; numberOfCars; numberOfCars--)
    {
        f>>carPosition;
        carDistance=tunnelLength-carPosition;
        f>>speed[carDistance];
    }
    groupSpeed=101;
    groupDistance=0;
    groupSize=0;
    for(carDistance=1; carDistance<=50000; carDistance++)
        if(speed[carDistance])
        {
            carSpeed=speed[carDistance];
            ///stay with this group <=>
            ///carTimeToExit >= groupTimeToExit <=>
            ///carDistance/carSpeed >= groupDistance/groupSpeed <=>
            ///groupSpeed*carDistance >= carSpeed*groupDistance
            if(groupSpeed*carDistance<=carSpeed*groupDistance)
                groupSize++;
            else
            {
                numberOfGroups++;
                groupSize=1;
                groupSpeed=carSpeed;
                groupDistance=carDistance;
            }
            maxSize=max(maxSize,groupSize);
        }
    g<<numberOfGroups<<'\n';
    g<<maxSize<<'\n';
    return 0;
}