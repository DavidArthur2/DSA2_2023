//
// Created by david.arthur on 3/2/2023.
//

#include "Rekurzio_Functions.h"

void printDigitsOfNumber(int n){
    if(n/10==0)printf("%d ",n);
    else {printDigitsOfNumber(n/10);
    printf("%d ",n%10);}

}
void printDigitsOfNumberReverse(int n){
    if(n/10==0)printf("%d ",n);
    else {printf("%d ",n%10);
        printDigitsOfNumberReverse(n/10);}
}
float averageDigitsOfNumber(int n, int numberOfDigits,
                            int sum){
    if(n/10==0){
        numberOfDigits++;
        sum=sum+n;
        return (float)sum/numberOfDigits;
    }
    return averageDigitsOfNumber(n/10,numberOfDigits+1,sum+n%10);
}