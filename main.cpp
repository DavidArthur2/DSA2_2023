#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

bool igeretes(int *x,int k)
{int i;
    for(i=1;i<=k-1;++i) {
        if (x[k] == x[i])return false;
        if(x[k]<x[i])return false;
    }
    return true;
}
int db;
void kiir(int *x,int k)
{int i;
    for(i=1;i<=k;++i)
        cout<<x[i]<<' ';
    cout<<endl;
    db++;
}
void BTP(int *x,int n,int k)
{
    for (x[k]=1; x[k]<=6; ++x[k])
    if (igeretes(x,k))
        if (k<n)
            BTP(x,n,k+1);
        else
            kiir(x,k);
}

int main()
{
    db=0;
    int *x, n=6;
    x = (int *) calloc(n, sizeof(int));
    for(int i=1;i<=n;i++)
    BTP(x, i, 1);
    cout << db;
    return 0;
}