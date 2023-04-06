#include <iostream>
#include <fstream>

using namespace std;
#include <vector>
void kiir(int x[],int n){
    for(int i=1;i<=n;i++)
        cout << x[i];
    cout<<endl;
}
void backtrck(int x[],int n, int k){
    for(int i=1;i<=n;i++){
        if(k<n)
            backtrck(x,n,k+1);
        else
            kiir(x,n);
    }
}

int main()
{
    int n=5;
    int x[]={1,1,2,3,4};
    backtrck(x,n,1);
}