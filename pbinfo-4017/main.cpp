#include <fstream>
using namespace std;
char v[1000001];
int main()
{
    ifstream cin("skip.in");
    ofstream cout("skip.out");
    string cuv;
    int cer;
    cin>>cer;
    if(cer==1)
    {
        while(cin>>cuv)
        {
            for(int i=0;i<cuv.size()/2;i++)
            {
                cout<<cuv[i]<<cuv[i+cuv.size()/2];
            }
            if(cuv.size()%2==1)
                cout<<cuv[cuv.size()-1];
            cout<<" ";
        }
    }
    else
    {
        while(cin>>cuv)
        {
            for(int i=0;i<cuv.size()/2;i++)
                v[i]=cuv[2*i],v[cuv.size()/2+i]=cuv[2*i+1];
            if(cuv.size()%2==1)
                v[cuv.size()-1]=cuv[cuv.size()-1];
            for(int i=0;i<cuv.size();i++)
                cout<<v[i];
            cout<<" ";
        }
    }
    return 0;
}