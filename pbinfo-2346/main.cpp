#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[10001];
    int i, t, j;
    FILE *f = fopen("paritatesiruri.in", "r");
    FILE *g = fopen("paritatesiruri.out", "w");
    fscanf(f,"%d", &t);
    for (i=0; i<t; i++) {
        fscanf(f,"%s", s);
        for (j=1; j<strlen(s); j=j+2)
            fprintf(g,"%c",s[j]);
        fprintf(g," ");
        for (j=0; j<strlen(s); j=j+2)
            fprintf(g,"%c",s[j]);
        fprintf(g,"\n");
    }
    return 0;
}