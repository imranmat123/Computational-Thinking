#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <math.h>
//1,1,2,3,5,8, 13

int fibi(int n){
    if(n>=3){
        return fibi(n-1) + fibi(n-2);
    }else{
        return 1;
    }

}
//5 = 5x4x3x2x1
//n! = (n-1)*(n-2)

//24 = 4 * 3
//6 = 3 * 2
//2 = 2 * 1
//1 = 1 * 1
//1 = 1 * 1
int fact(int n){
    if(n <= 1){
        return 1;
    }else{
        return (n-1) * fact(n-1);
    }
}


int main() {
    printf("%d",fact(5));
    return 0;
}








