#include <bits/stdc++.h>
using namespace std;
struct BST
{
    int val, fr;
    BST *st, *dr;
    BST(int v)
    {
        val = v; fr = 1;
        st = dr = NULL;
    }
};
BST *rad;
ifstream  fin("bst.in");
ofstream fout("bst.out");
void Inserare(int x)
{
    /// arborele este vid
    if (rad == NULL)
    {
        rad = new BST(x);
        return;
    }
    BST *p, *q;
    p = q = rad;
    while (p != NULL)
    {
        if (p->val == x)
        {
            p->fr++;
            return;
        }
        q = p;
        if (p->val < x) p = p->dr;
        else p = p->st;
    }
    p = new BST(x);
    if (q->val > x) q->st = p;
    else q->dr = p;
}
void CreareBST()
{
    int n, x;
    fin >> n;
    while (n--)
    {
        fin >> x;
        Inserare(x);
    }
}
void Inord(BST *p)
{
    if (p != NULL)
    {
        Inord(p->st);
        int cnt = p->fr;
        while (cnt--)
            fout << p->val << " ";
        Inord(p->dr);
    }
}
int main()
{
    rad = NULL;
    CreareBST();
    Inord(rad);
    fout << "\n";
    fout.close();
    return 0;
}