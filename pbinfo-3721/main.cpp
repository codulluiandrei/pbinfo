/**
Sursa oficiala de 100 de puncte, fara functii si fara vectori!
Cu drag,
Alexandru
**/
#include <stdio.h>
#define PRINT_MULTIPLES_OF_4 0
#define PRINT_LABEL 1
#define PRINT_OTHER_EVEN 2
#define PRINT_NEWLINE 3
int main() {
    FILE *fin = fopen("cochilie.in", "r");
    FILE *fout = fopen("cochilie.out", "w");
    int c; /// task index
    int n; /// shell order
    int p; /// row number
    fscanf(fin,"%d%d", &c, &n);
    if (c == 2) {
        fscanf(fin,"%d", &p);
    }
    int i, above = 0, previous = 0, current = 1;
    for (i = 2; i <= n; i++) {
        int aux = current;
        current += previous;
        previous = aux;
        if (i % 4 == 1) {
            above += current;
        }
    }
    if (c == 1) {
        if (n % 2 == 0) {
            fprintf(fout,"%d %d\n", current, current + previous);
        } else {
            fprintf(fout,"%d %d\n", current + previous, current);
        }
    } else {
        previous = 0;
        current = 1;
        int label = 1;
        while (label % 2 == 0 || above >= p || p > above + current + previous) {
            label++;
            int aux = current;
            current += previous;
            previous = aux;
            if (label % 4 == 1) {
                above -= current;
            }
        }
        /// label is the only odd number in the output
        /// all even numbers greater than label are to be printed as well
        int phase = PRINT_MULTIPLES_OF_4;
        int k = n / 4 * 4; /// largest multiple of 4 <= n
        while (phase != PRINT_NEWLINE) {
            int toPrint = 0;
            switch (phase) {
            case PRINT_MULTIPLES_OF_4:
                if (k > label) {
                    toPrint = k;
                    k -= 4;
                } else {
                    phase = PRINT_LABEL;
                    toPrint = label;
                    phase = PRINT_OTHER_EVEN;
                    k = label + label % 4; /// smallest multiple of 4 plus 2 > label
                }
                break;
            case PRINT_OTHER_EVEN:
                if (k <= n) {
                    toPrint = k;
                    k += 4;
                } else {
                    phase = PRINT_NEWLINE;
                }
            }
            if (toPrint != 0) {
                previous = 0;
                current = 1;
                for (i = 2; i <= toPrint; i++) {
                    int aux = current;
                    current += previous;
                    previous = aux;
                }
                for (i = 0; i < current; i++) {
                    fprintf(fout,"%d ", toPrint);
                }
            }
        }
    }
    return 0;
} 