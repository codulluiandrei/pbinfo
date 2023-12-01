#include <stdio.h>
int main()
{
    int i,k=1,ck,nv,j,v[1001],nk=0,gata=0,cer,pas=0,n,ok;
    int T=0;
    char c;
    FILE * f=fopen("poarta.in","r");
    FILE * g=fopen("poarta.out","w");
    fscanf(f,"%d %d", &cer, &n);
    nv=0;ok=0;
    while(!feof(f))
        {

            fscanf(f,"%c", &c);
            if(c>='0'&&c<='9')
            {
                v[++nv]=c-'0';
            }
        }
fclose(f);
    ck=n;
    while(ck)
    {
        nk++;ck=ck/10;
    }

    while(!gata)
    {
        j=0;k++;
        if(v[nv]%2==0)
            {
                T+=2;pas=2;
                for(i=1;i<=nv;i++)
                    {
                    j=j*10+v[i];
                    v[i]=j/2;j=j%2;

                    }
            }
        else
            {
                T++;pas=1;
                v[nv]--;
            }
        if(v[1]==0)
        {
            i=1;j=1;
            while(v[i]==0)i++;nv=nv-i+1;
            while(j<=nv)v[j++]=v[i++];
        }

        if(nv<=nk)
        {
            ck=0;
            for(i=1;i<=nv;i++) ck=ck*10+v[i];
            if(ck<=n)gata=1;
        }
    }
    if(pas==2&&ck*2==n+1){ck=n;T=T-1;}
    if(cer==1) fprintf(g,"%d\n",k);//ne minim de dale
            else fprintf(g,"%d\n",T);//nr minim de picaturi
    fclose(g);
    return 0;
}
