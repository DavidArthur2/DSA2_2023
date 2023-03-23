//
// Created by david.arthur on 3/23/2023.
//

#ifndef DSA2_2023_GYAKORLAS_H
#define DSA2_2023_GYAKORLAS_H


#include <cstdlib>
#include <iostream>
#include <math.h>

int tomb_osszeg(int *t, int n);

int tomb_min(int *t,int n);
int tomb_minaux(int *t, int n, int min);

int tomb_max(int *t,int n);
int tomb_maxaux(int *t, int n, int min);

int comp(const void *a, const void *b);
void tizennegyes();
int bin_ker(int *t, int e, int u,int lepes=0);

float tomb_atlag(int *t, int n,int i=0);

int tomb_szorz(int *t, int n,int i=0);

int szamjegy_szam(int a,int szj);

int fordit(int a,int sz_sz);
int count(int a);
int palindrome(int a);

#endif //DSA2_2023_GYAKORLAS_H
