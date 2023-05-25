//
// Created by david.arthur on 5/11/2023.
//

#include <iostream>
#include <fstream>

using namespace std;



struct ellista{
    int el1,el2,suly;
};

bool kore(ellista *lista,int elsz, ellista el){
    int ok=0;
    for(int i=0;i<elsz;i++)
    {
        if(lista[i].el1 == el.el1 || lista[i].el1 == el.el2)ok++;
        //if(lista[i].el2 == el.el1 || lista[i].el2 == el.el2)ok++;
    }
    if(ok>=2)return true;
    return false;
}
int comp3(const void*a, const void*b){
    int sulya=(*(int*)a);
    int sulyb=(*(int*)b);

    if(sulya>sulyb)return 1;
    else if(sulya<sulyb)return -1;
    return 0;
}
ellista* kruskal(ellista *lista,int elsz,int csp){
    ellista *el=(ellista*)malloc((csp-1)*sizeof(ellista));
    int k=0;
    for(int i=0;i<(csp-1) && k<elsz;i++){
        if(!kore(el,i,lista[k])){
            el[i]=lista[k++];
        }
        else{
            i--;
            k++;
        }
    }
    if(k==elsz){cout<<"Nincs megoldas"<<endl;return nullptr;}
    return el;
}
int main45(){
    ifstream be("graph.txt");
    int csp,el;
    be >> csp >> el;
    ellista *elek=(ellista*)malloc(el*sizeof(ellista));
    for(int i=0;i<el;i++){
        be >> elek[i].el1 >> elek[i].el2 >> elek[i].suly;
    }

    qsort(elek,el,sizeof(ellista), comp3);

    ellista *fa=kruskal(elek,el,csp);

    for(int i=0;i<(csp-1);i++)cout << fa[i].el1 << " " << fa[i].el2 << endl;
    return 0;
}