//
// Created by david.arthur on 5/8/2023.
//

#include "kettes.h"
int comp2(const void*a, const void*b){
    beteg x=*((beteg*)a);
    beteg y=*((beteg*)b);

    if(x.perc<y.perc)return -1;
    if(x.perc>y.perc)return 1;
    return 0;
}
void kettes(){
    int db;
    ifstream be("betegek.txt");
    be >> db;
    beteg *betegek=(beteg*)malloc(sizeof(beteg)*db);
    for(int i=0;i<db;i++)
    {
        char tmp1[24],tmp2[12];
        be >> tmp1 >> tmp2;
        strcat(tmp1," ");
        strcat(tmp1,tmp2);
        strcpy(betegek[i].nev,tmp1);
        be >> betegek[i].perc;
    }

    qsort(betegek,db,sizeof(beteg),comp2);

    //for(int i=0;i<db;i++)cout << betegek[i].nev <<  ' ' << betegek[i].perc << endl;
    be.close();

    int ora=8,perc=0;

    for(int i=0;i<db;i++){
        cout << betegek[i].nev <<":"<< ora << " ora " << perc << " perckor" << endl;
        perc+=betegek[i].perc;
        if(perc>60){ora=ora+perc/60;perc=perc%60;}
    }

}