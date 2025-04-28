# include <deque>
# include <fstream>
using namespace std;
ifstream f("maxsecvk.in");
ofstream g("maxsecvk.out");
deque <int > deq;
int n, k;
int A[100001];
int main()
{
    int i;
    f >> n >> k;
    for (i=1; i<=n; ++i)
        f >> A[i];
    for (i=1; i<=k; ++i)
    {
        while (!deq.empty() && A[deq.back()] <= A[i])
            deq.pop_back();
        deq.push_back(i);
    }
    for (  ; i<=n+1; ++i)
    {
        g << A[deq.front()] << " ";
        while (!deq.empty() && deq.front() <= i-k)
                deq.pop_front();
        while (!deq.empty() && A[deq.back()] <= A[i])
            deq.pop_back();
        deq.push_back(i);
    }
    return 0;
}