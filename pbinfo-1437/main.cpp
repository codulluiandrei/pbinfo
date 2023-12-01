#include <cstdio>

using namespace std;

int P, N, a, b;

int main() {
    freopen("fractii4.in","r",stdin);
    freopen("fractii4.out","w",stdout);

    scanf("%d %d\n", &P, &N);

    for(int i = 1; i <= N; ++i) {
        scanf("%d %d\n", &a, &b);

        int r = a % b;
        int auxA = a, auxB = b;

        while(r) {
            auxA = auxB;
            auxB = r;
            r = auxA % auxB;
        }

        if(P == 2) {
            printf("%d/%d\n", a / auxB, b / auxB);
        }
        else {
            if(auxB == 1) {
                printf("-1\n");
            }
            else {
                int d = 2;
                int answer = 1;
                int putere = 0;

                while(d <= auxB) {
                    while(auxB % d == 0) {
                        ++putere;
                        auxB /= d;
                    }

                    if(d == 2) {
                        ++d;
                    }
                    else {
                        d += 2;
                    }

                    answer *= putere + 1;
                    putere = 0;
                }

                printf("%d\n", answer - 1);
            }
        }
    }

    return 0;
}
