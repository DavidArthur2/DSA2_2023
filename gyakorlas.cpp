//
// Created by david.arthur on 3/23/2023.
//

#include "gyakorlas.h"

int tomb_osszeg(int *t, int n){
    if(n==0)return 0;
    return t[n-1]+tomb_osszeg(t,n-1);
}
int tomb_min(int *t,int n){
    int min=t[0];
    min=tomb_minaux(t,n,min);
    return min;
}
int tomb_minaux(int *t, int n, int min){
    if(n==0)return min;
    return tomb_minaux(t,n-1,min<t[n-1]?min:t[n-1]);
}
int tomb_max(int *t,int n){
    int min=t[0];
    min=tomb_minaux(t,n,min);
    return min;
}
int tomb_maxaux(int *t, int n, int min){
    if(n==0)return min;
    return tomb_minaux(t,n-1,min>t[n-1]?min:t[n-1]);
}

int comp(const void *a, const void *b){
    int *x=(int*)a;
    int *y=(int*)b;
    if((*x)>(*y))return 1;
    else if((*x)<(*y))return -1;
    return 0;
}
void tizennegyes(){
    int n=7;
    int *t = (int*)malloc(sizeof(int)*n);
    t[0]=3;t[1]=5;t[2]=-7;t[3]=8;t[4]=2;t[5]=-1;t[6]=6;
    qsort(t,n,sizeof(int),comp);
    std::cout << bin_ker(t,0,n-1);
}
int bin_ker(int *t, int e, int u,int lepes)
{
    lepes++;
    if(t[u/2]==-1)return lepes;
    if(e==u && t[e]==-1)return lepes;
    if(e==u)return -1;

    if(t[u/2]>-1)return bin_ker(t,e,u/2-1,lepes);
    else return bin_ker(t,u/2+1,u,lepes);
}
//-7 -1 2 3 5 6 8

float tomb_atlag(int *t, int n,int i){
    if(i==n)return 0;
    int sum=t[i]+tomb_atlag(t,n,i+1);
    if(i==0)return (float)((float)sum)/((float)n);
    return sum;
}
int tomb_szorz(int *t, int n,int i){
    if(i==n)return 0;
    int sum=t[i]*tomb_atlag(t,n,i+1);
    return sum;
}
int szamjegy_szam(int a,int szj){
    if(a==0)return 0;
    if(a%10==szj)return 1+szamjegy_szam(a/10,szj);
    return szamjegy_szam(a/10,szj);
}
int count(int a){
    if(a==0)
        return 0;
    return count(a/10)+1;
}
int fordit(int a,int sz_sz){
    if(a==0)return 0;
    return (a%10)*(int)pow(10,sz_sz-1)+fordit(a/10,sz_sz-1);
}
int palindrome(int a){
    int n=count(a);
    if(fordit(a,n) == a)return 1;
    return 0;
}