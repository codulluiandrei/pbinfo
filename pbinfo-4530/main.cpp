/*
   Solves the problem using dynamic programming,
   time complexity: O ( item_nr * slot_nr )
*/
#include <fstream>
#define   MAX_SLOT_NR  	101
#define   MAX_ITEM_NR   101
using namespace std;
ifstream fin("flowers.in");
ofstream fout("flowers.out");
/* the table weight keeps the weight of each item in each slot  */
/* it will also be used to calculate the best (maximum) weights */
int    weight[MAX_ITEM_NR][MAX_SLOT_NR];
/* the table index will be used to keep the solution(s) */
int    f_index[MAX_ITEM_NR][MAX_SLOT_NR];
int    slot_nr;   /* the number of slots */
int    item_nr;   /* the number of items */
void get_input()
{
    int i,j;
    fin >> item_nr >> slot_nr;
    for (i=0; i < item_nr; i++)
        for (j=0; j < slot_nr; j++)
            fin >> weight[i][j];
}
void solve()
/* calculates the maximum sum of weights for each item in each slot */
/* and also fills the 'index' table with info about how we obtained */
/* this maximum (needed to output the solutions)                    */
{
    int i, j, k, wmax, imax;
    for (i=1; i < item_nr; i++)
    {
        imax = i-1;
        wmax = weight[i-1][imax];
        for (j=i; j <= (slot_nr - item_nr + i); j++)
        {
            if (weight[i-1][j-1] > wmax)
            {
                wmax = weight[i-1][j-1];
                imax = j-1;   /* record the index of maximum */
            }
            weight[i][j] += wmax;
            f_index[i][j] = imax;
        }
    }
}
void print_slots(int item, int slot)
/* postorder recursive function */
{
    int prev_slot;
    if (item == 0) fout << slot+1 << " ";
    else
    {
        prev_slot = f_index[item][slot];
        print_slots(item-1, prev_slot);
        fout << slot+1 << " ";
    }
}
void print_solution()
{
    int wmax;
    int imax;
    int j;
    /* take as max the first one */
    imax = item_nr - 1;
    wmax = weight[item_nr-1][imax];
    for (j=item_nr-1; j < slot_nr; j++)
        if ( weight[item_nr-1][j] > wmax )
        {
            wmax = weight[item_nr-1][j];
            imax = j;
        }
    fout << weight[item_nr-1][imax] << "\n";
    print_slots(item_nr-1, imax);
}
int main()
{
    get_input();
    solve();
    print_solution();
    return 0;
}