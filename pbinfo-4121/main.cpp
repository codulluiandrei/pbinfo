/*
 * Author: Andrei Cotor
 * Student, Babes-Bolyai University, Cluj-Napoca
*/
#include <fstream>
using namespace std;
const int mod=1e9+7;
class DpState
{
public:
    int lungMin, posib;
    void reset()
    {
        posib=0;
        lungMin=1000000000;
    }
    /*
     * @brief Combines two states of the Dp and memorises the best one of them
    */
    void combineStates(const DpState &other)
    {
        if(lungMin>other.lungMin)
        {
            lungMin=other.lungMin;
            posib=other.posib;
        }
        else if(lungMin==other.lungMin)
        {
            posib+=other.posib;
            if(posib>=mod)
                posib-=mod;
        }
    }
};
int A[100005];
DpState Dp[2][15][2][1005]; // i - is in an active sequence, j - the number of sequences, k - the index we arived at, l - the sum
int main()
{
    ifstream fi("dragonfruit.in");
    ofstream fo("dragonfruit.out");
    int T;
    fi>>T;
    for(int t=0; t<T; t++)
    {
        int S, N, K;
        fi>>N>>K>>S;
        for(int i=1; i<=N; i++)
        {
            fi>>A[i];
        }
        int pos=0;
        int lung=1000000000;
        if(N>2000)
        {
            int sum=0;
            int st=1;
            for(int dr=1; dr<=N; dr++)
            {
                sum+=A[dr];
                while(st<=dr && sum-A[st]>=K)
                {
                    sum-=A[st];
                    st++;
                }
                if(sum==K)
                {
                    if(dr-st+1<lung)
                    {
                        lung=dr-st+1;
                        pos=1;
                    }
                    else if(dr-st+1==lung)
                    {
                        pos++;
                    }
                }
            }
        }
        if(N<=2000)
        {
            for(int i=0; i<=S; i++)
            {
                for(int j=0; j<=1; j++)
                {
                    for(int k=0; k<=K; k++)
                    {
                        Dp[0][i][j][k].reset();
                        Dp[1][i][j][k].reset();
                    }
                }
            }
            Dp[0][0][0][0].lungMin=0;
            Dp[0][0][0][0].posib=1;
            int crIdx=1;
            for(int i=1; i<=N; i++)
            {
                for(int nrSeq=0; nrSeq<=S; nrSeq++)
                {
                    for(int sum=0; sum<=K; sum++)
                    {
                        Dp[0][nrSeq][crIdx][sum].reset();
                        Dp[1][nrSeq][crIdx][sum].reset();
                        // i will not be part of a sequence
                        Dp[0][nrSeq][crIdx][sum]=Dp[0][nrSeq][1-crIdx][sum];
                        if(nrSeq>0 && A[i]<=sum)
                        {
                            // continue the last sequence
                            DpState cr=Dp[1][nrSeq][1-crIdx][sum-A[i]];
                            cr.lungMin+=1;
                            Dp[1][nrSeq][crIdx][sum].combineStates(cr);
                            // start a new sequence
                            cr=Dp[0][nrSeq-1][1-crIdx][sum-A[i]];
                            cr.lungMin+=1;
                            Dp[1][nrSeq][crIdx][sum].combineStates(cr);
                        }
                        // mark the posibility that the sequence containing A[i] may finish at i
                        Dp[0][nrSeq][crIdx][sum].combineStates(Dp[1][nrSeq][crIdx][sum]);
                    }
                }
                crIdx=1-crIdx;
            }
            crIdx=N%2;
            for(int i=0; i<=S; i++)
            {
                // 0 contains both cases, so taking 1 into account would be obsolete
                if(Dp[0][i][crIdx][K].lungMin<lung)
                {
                    lung=Dp[0][i][crIdx][K].lungMin;
                    pos=Dp[0][i][crIdx][K].posib;
                }
                else if(Dp[0][i][crIdx][K].lungMin==lung)
                {
                    pos=pos+Dp[0][i][crIdx][K].posib;
                    if(pos>=mod)
                        pos-=mod;
                }
            }
        }
        if(lung==1000000000)
            fo<<"0 0\n";
        else
            fo<<lung<<" "<<pos<<"\n";
    }
    fi.close();
    fo.close();
    return 0;
}