#include <fstream>
using namespace std;
int a[100];
int main()
{   int n,i,k;
    ifstream fin("n3579.in");
    ofstream fout("n3579.out");
    fin>>n;
    k=0;
    while (n>1)
        switch (n)
        {   case 2:
            {
                n=1;
                a[++k]=9;
                a[++k]=3;
                a[++k]=5;
                break;
            }
            case 3:
            {
                n=1;
                a[++k]=3;
                break;
            }
            case 4:
            {
                n=1;
                a[++k]=9;
                a[++k]=7;
                a[++k]=7;
                a[++k]=7;
                a[++k]=7;
                a[++k]=7;
                break;
            }
            case 5:
            {
                n=1;
                a[++k]=9;
                a[++k]=3;
                a[++k]=7;
                a[++k]=7;
                break;
            }
            case 6:
            {
                n=1;
                a[++k]=3;
                a[++k]=9;
                a[++k]=3;
                a[++k]=5;
                break;
            }
            case 7:
            {
                n=1;
                a[++k]=5;
                a[++k]=9;
                a[++k]=3;
                a[++k]=5;
                break;
            }
            default:
                if (n%3==0)
                {
                    n=n/3;
                    a[++k]=3;
                }
                else
                    if ((n-5)%3==0)
                    {
                        n=(n-5)/3;
                        a[++k]=5;
                        a[++k]=3;
                    }
                    else
                    {
                        n=(n-7)/3;
                        a[++k]=7;
                        a[++k]=3;
                    }
        }
    for (i=k;i>0;i--)
        fout<<a[i]<<" ";
    fout<<"\n";
    fin.close();
    fout.close();
    return 0;
}