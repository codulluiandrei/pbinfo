#include <fstream>
#include <vector>
#include <cstring>
#define DIM 1010

using namespace std;

vector < pair<int, int> > sol;
int v[DIM];
char s[DIM][35], aux[35];
char w[DIM][35];
int n, m, putere, p, d, i, j, last, t, k, st, dr, mid;

ifstream fin ("sort2dist.in");
ofstream fout("sort2dist.out");

int myStrcmp(char *s1, char *s2) {
    if (strlen(s1) == strlen(s2))
        return strcmp(s1, s2);
    else
        if (strlen(s1) < strlen(s2))
            return -1;
        else
            return 1;
}

void schimba(int x, int y) {
    sol.push_back(  make_pair(x, y) );
    int aux = v[x];
    v[x] = v[y];
    v[y] = aux;
}

int main() {

    fin>>n;
    for (i=1;i<=n;i++) {
        fin>>s[i];
        strcpy(w[i], s[i]);

//        v[i] = i;
    }

    for (i=1;i<n;i++)
        for (j=i+1;j<=n;j++) {
            if (myStrcmp(w[i], w[j]) > 0) {
                strcpy(aux, w[i]);
                strcpy(w[i], w[j]);
                strcpy(w[j], aux);
            }
        }
    k = 1;
    for (i=2;i<=n;i++) {
        if (myStrcmp(w[i], w[k]) != 0) {
            k++;
            strcpy(w[k], w[i]);
        }
    }

    for (i=1;i<=n;i++) {
        st = 1;
        dr = k;
        while (st <= dr) {
            mid = (st + dr)/2;
            if (myStrcmp(s[i], w[mid]) == 0) {
                v[i] = mid;
                break;
            }
            if (myStrcmp(s[i], w[mid]) < 0)
                dr = mid - 1;
            else
                st = mid + 1;
        }
    }

    for (i=n;i>=2;i--) {
        m = v[1];
        p = 1;
        for (j=2;j<=i;j++)
            if (v[j] > m) {
                m = v[j];
                p = j;
            }
        if (p != i) {
            d = i-p;

            putere = 1;
            last = p;
            while (d!=0) {
                if (d%2 == 1) {
                    schimba(last+putere, last);
                    last += putere;
                }
                d = d/2;
                putere = putere*2;
            }

        }
    }

    fout<<sol.size()<<"
";
    for (i=0;i<sol.size();i++) {
        fout<<sol[i].first<<" "<<sol[i].second<<"
";
    }
    return 0;
}
