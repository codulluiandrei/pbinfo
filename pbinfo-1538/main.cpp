#include <fstream>
#define Fin  "sudest.in"
#define Fout "sudest.out"
#define Nmax 100
using namespace std;
int N;		//numarul de linii
int K;		//numarul de comenzi
int A[Nmax][Nmax];	//memoreaza cantitatea de produs
int C[Nmax][Nmax];	//C[i][j]=cantitatea maxima de cartofi culeasa pe un traseu ce
                        //porneste din (1,1) si se termina in (i,j), respectand conditiile problemei
unsigned char P[Nmax][Nmax];
int  Move[2*Nmax];   //memoreaza cele K comenzi
ofstream g(Fout);
void read_data()
 {
  int i,j;
  ifstream f(Fin);
  f>>N;
  for(i=0;i<N;i++)
    for(j=0;j<N;j++) f>>A[i][j];
  f>>K;
  for(i=1;i<=K;i++) f>>Move[i];
  f.close();
 }
void init()
 {
  int i,j;
  for(i=0;i<N;i++)
    for(j=0;j<N;j++) {C[i][j]=-1; P[i][j]=255;}
 }
int posibil(int x, int y)
  {
   return 0<=x && 0<=y && x<N && y<N;
  }
void drum(int x, int y, int pas)
 {
  int i, gasit;
  if(x==0 && y==0) g<<1<<" "<<1<<'\n';
  else
   {
    gasit=0;
    if (posibil(x,y-Move[pas]))
       if (C[x][y-Move[pas]]==C[x][y]-A[x][y] && P[x][y-Move[pas]]==pas-1)
          {
            drum(x,y-Move[pas],pas-1);
            g<<x+1<<" "<<y+1<<endl;
            gasit=1;}
   if (!gasit)
   if (posibil(x-Move[pas],y))
       if (C[x-Move[pas]][y]==C[x][y]-A[x][y] && P[x-Move[pas]][y]==pas-1)
          {
            drum(x-Move[pas],y,pas-1);
            g<<x+1<<" "<<y+1<<endl;}
   }
 }
void solve()
 {
  int i,j, h;
  P[0][0]=0; C[0][0]=A[0][0];
  for (i=1; i<=K; i++)
      for (j=0; j<N; j++)
          for (h=0; h<N; h++)
              if (P[j][h]==i-1)
                 {
                 if (posibil(j+Move[i],h))
                    if (C[j][h]+A[j+Move[i]][h]>C[j+Move[i]][h])
                       {P[j+Move[i]][h]=i;
                        C[j+Move[i]][h]=C[j][h]+A[j+Move[i]][h];}
                 if (posibil(j,Move[i]+h))
                    if (C[j][h]+A[j][Move[i]+h]>C[j][Move[i]+h])
                       {P[j][Move[i]+h]=i;
                        C[j][Move[i]+h]=C[j][h]+A[j][Move[i]+h];}
                 }
  g<<C[N-1][N-1]<<'\n';
  drum(N-1,N-1,K);
  g.close();
 }
int main()
 {
  read_data();
  init();
  solve();
  return 0;
 }