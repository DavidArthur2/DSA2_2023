//
// Created by david.arthur on 5/8/2023.
//

#include "egyes.h"


int comp(const void*a, const void*b){
    int *x=(int*)a;
    int *y=(int*)b;
    if((*y) > (*x))return 1;
    else if((*y) < (*x))return -1;
    return 0;
}
void egyes(){
    int bsz;
    cin >> bsz;
    int *bankjegyek=(int*)malloc(sizeof(int)*bsz);
    for(int i=0;i<bsz;i++)cin>>bankjegyek[i];
    int szam;
    cin >> szam;

    qsort(bankjegyek,bsz,sizeof(int),comp);

    //for(int i=0;i<bsz;i++)cout << bankjegyek[i] << ' ';
    int sum=0,i=0,eredeti=szam;
    while(sum<eredeti && i<bsz){
        int tmp=szam/bankjegyek[i];
        if(tmp>=1)
        {
            sum=sum+bankjegyek[i]*(tmp);
            szam=szam-bankjegyek[i]*(tmp);
            cout << tmp << 'x'<<bankjegyek[i]<< ' ';
        }
        i++;
    }
    if(sum!=eredeti)cout <<endl<< "Nincs megoldas";
}