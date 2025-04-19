#include<cstdio>
int main()
{
    FILE* f=fopen("legos.in", "r");
    FILE* g=fopen("legos.out", "w");
    int c, P, i, ans=0;
    fscanf(f, "%d%d", &c, &P);
    if(c==1)
	{
		for(i=3;i*i<=P;++i);
		fprintf(g, "%d\n", (i-1)*(i-1));
	}
    else if(c==2)
	{
		if(P<16)
			fprintf(g, "%d\n", 9);
		else if(P<22)
			fprintf(g, "%d\n", 16);
		else
			fprintf(g, "%d\n", (P-9)/13*13+9);
	}
    else
    {
		for(i=3;i*i<P;++i)
			if(P%i==0)
				ans+=2;
		if(i*i==P)
			++ans;
		fprintf(g, "%d\n", ans);
    }
    fclose(f);
    fclose(g);
    return 0;
}