#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
ifstream in("ratc2.in");
ofstream out("ratc2.out");
struct pasager{
    char prenume[51], nume[51];
    int penalizari;
}v[105], *ptr;
char N[51], P[51];
int main() {
    int n, p, k = 0, ok, maxx = -1;
    in >> n >> p;
    for(int i = 0; i < n; i++){
        in>>P>>N>>ok;
        bool gasit = 0;
        for(int j = 0; j < k; j++){
            if(strcmp(v[j].nume, N) == 0 && strcmp(v[j].prenume, P) == 0){
                gasit = 1;
                if(!ok) {
                    v[j].penalizari++;
                }
            }
        }
        if(!gasit){
            strcpy(v[k].prenume, P);
            strcpy(v[k].nume, N);
            if(!ok) {
                v[k].penalizari++;
            }
            k++;
        }
    }
    if(p==1){
        for(int i = 0; i < k; i++){
            if(v[i].penalizari > maxx){
                maxx = v[i].penalizari;
                ptr = &v[i];
            }
            else if(v[i].penalizari == maxx){
                if(strcmp(ptr->prenume, v[i].prenume) > 0){
                    ptr = &v[i];
                }
                else if(strcmp(ptr->prenume, v[i].prenume) == 0){
                    if(strcmp(ptr->nume, v[i].nume) > 0){
                        ptr = &v[i];
                    }
                }
            }
        }
        out << ptr->prenume << " " << ptr->nume << " " << ptr->penalizari;
    }
    else{
        /// sortare bubble
        bool done = 0;
        while(!done){
            done = 1;
            for(int i = 0; i < k - 1; i++){
                if(v[i].penalizari < v[i+1].penalizari){
                    swap(v[i], v[i+1]);
                    done = 0;
                }
                else if(v[i].penalizari == v[i+1].penalizari){
                    if(strcmp(v[i].prenume, v[i+1].prenume) > 0){
                        swap(v[i], v[i+1]);
                        done = 0;
                    }
                    else if(strcmp(v[i].prenume, v[i+1].prenume) == 0){
                        if(strcmp(v[i].nume, v[i+1].nume) > 0){
                            swap(v[i], v[i+1]);
                            done = 0;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < k; i++){
            out << v[i].prenume << " " << v[i].nume << " " << v[i].penalizari << "\n";
        }
    }
    return 0;
}