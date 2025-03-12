#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <math.h>

int digPow(int n, int p) {
    int a[10];
    int size = sizeof(a) / sizeof(a[0]);
    int i = 0;
    int sum = 0;
    int np = p;
    int d = n;
    while(n>0){
        a[i] = n%10;
        n = n/10;
        i++;
    }

    for(int j = i -1; j >= 0; j--){
            int temp = a[j];
            sum = sum + pow(temp,np);
            np++;
    }
    int k = sum/d;
    if(sum % d == 0){
        return k;
    }else if(sum % d != 0){
        return -1;
    }

    return 0;
}



int main() {

    // Test case 1
    int result1 = digPow(89, 1);
    printf("digPow(89, 1) = %d\n", result1);

    // Test case 2
    int result2 = digPow(92, 1);
    printf("digPow(92, 1) = %d\n", result2);

    // Test case 3
    int result3 = digPow(695, 2);
    printf("digPow(695, 2) = %d\n", result3);

    // Test case 4
    int result4 = digPow(46288, 3);
    printf("digPow(46288, 3) = %d\n", result4);


    return 0;
}








