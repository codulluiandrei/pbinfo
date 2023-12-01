#include <iostream>

using ull = unsigned long long;

char c;
ull n;

void decToBin(ull n)
{
    bool BinNum[64];

    int i=0;
    while(n>0)
    {
        BinNum[i]=n%2;
        n=n/2;
        i++;
    }

    for(int j=i-1; j>=0; j--) std::cout<<BinNum[j];
}

void decToOct(ull n)
{
    int OctNum[100];

    int i=0;
    while(n!=0)
    {
        OctNum[i]=n%8;
        n/=8;
        i++;
    }

    for(int j=i-1; j>=0; j--) std::cout<<OctNum[j];
}

void decToHex(ull n)
{
    char HexNum[100];

    int i=0, temp=0;
    while(n!=0)
    {
        temp=0;
        temp=n%16;

        if(temp<10) HexNum[i]=temp+48;
        else HexNum[i]=temp+55;

        i++;

        n/=16;
    }

    for(int j=i-1; j>=0; j--) std::cout<<HexNum[j];
}

int main()
{
	std::cin>>c>>n;

	switch(c)
	{
    case 'b':
        decToBin(n);
        break;

    case 'o':
        decToOct(n);
        break;

    case 'h':
        decToHex(n);
        break;
	}

	return 0;
}
