//
// Created by david.arthur on 5/25/2023.
//

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
char *targyak[50];
bool helyes(int *x, int k){
    if(strcmp(targyak[x[1]],"Adat es alg 2") != 0)return false;

    for(int i=0;i<k;i++){
        if(x[i]==x[k])return false;

    }
    return true;
}
void kiir(int *x, int k){
    for(int i=0;i<k;i++)
        cout << targyak[x[i]] << ';';
    cout << endl;
}
void bt(int *x,int n, int k){
    for(x[k]=0;x[k]<n;x[k]++){
        if(helyes(x,k)) {
            if (k < n - 1) {
                bt(x,n,k+1);
            }
            else
                kiir(x,n);
        }
    }
}

int main(){
    freopen("be.txt","r",stdin);
    char *line=(char*)malloc(sizeof(char)*2);
    int *x;
    int n;
    cin >> n;
    cin.getline(line,1);
    x=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) {
        targyak[i]=(char*)malloc(sizeof(char)*50);
        cin.getline(targyak[i], 50);
    }

    bt(x,n,0);

}