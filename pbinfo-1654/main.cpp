#include <cstring>
int nr_vocale(char *sir)
{
    if(sir[0] == NULL)
        return 0;

    if(strchr("aeiouAEIOU", sir[0]))
        return 1 + nr_vocale(sir + 1);

    return nr_vocale(sir + 1);
}