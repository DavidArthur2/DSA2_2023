#include <iostream>
#include <fstream>

using namespace std;
#include <vector>

typedef struct{
    int kifok, befok, fok, *kiszomszedok, *beszomszedok, *szomszedok;
    int szin, apa;
}PONT;

int main()
{
    int n,m;
    PONT* szLista = (PONT*)calloc(n,sizeof(PONT));
    for( int i = 0 ; i < n ; ++i ){
        szLista[i].kiszomszedok = (int*)calloc(n,sizeof(int));
        szLista[i].beszomszedok = (int*)calloc(n,sizeof(int));
//szLista[i].szomszedok = (int*)calloc(n,sizeof(int))
    }
    for( int i = 0 ; i < m ; ++i ){ fscanf(fin, "%i%i%i",&a,&b); --a;--b;
        szLista[a].kiszomszedok[szLista[a].kifok] = b; ++szLista[a].kifok;
        szLista[b].beszomszedok[szLista[b].befok] = a; ++szLista[b].befok;
//szLista[a].szomszedok[szLista[a].fok] = b; ++szLista[a].fok;
//szLista[b].szomszedok[szLista[b].fok] = a; ++szLista[b].fok; }
        for( int i = 0 ; i &lt; n ; ++i ){
            szLista[i].kiszomszedok = (int*)realloc(szLista[i].kiszomszedok,szLista[i].kifok*sizeof(int));
            szLista[i].beszomszedok = (int*)realloc(szLista[i].beszomszedok,szLista[i].befok*sizeof(int));
//szLista[i].szomszedok = (int*)realloc(szLista[i].szomszedok,szLista[i].fok*sizeof(int)) }
}
void dfsTravers( int u ){
            dfsvisited[u] = 1;
            cout  <<chars[u] <<;                                                                                                //Mélységi bejárás szerinti meglátogatási sorrend
            for( int j = 0 ; j  < adjList[u].size() ; ++j ){
                        int v = adjList[u][j];
                        if ( !dfsvisited[v] ){
                                    dfsTravers(v);
                            }
                }
}