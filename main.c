#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <time.h>

int linear_search(int* a, int target, int sizeOfAray){
    for(int i=0; i <= sizeOfAray; i++){
        if (target == a[i]){
            printf("the target is: %d", a[i]);
            return 0;
        }
    }
    return -1;
}

int create100000Array(int* a){
    for(int i = 0; i <= 1000000; i++){
        a[i] = i +1;
        printf("%d",i);
        printf("\n");
    }
}

int binary_search(int* a, int target, int size){
    int upper = size -1;
    int lower = 0;


    printf("at index 99 we have %d", a[upper]);
    printf("\n");


    while(lower != upper){
        int middle = lower + (upper - lower) / 2;
        if(a[middle] == target){
            printf("\n");
            printf("you found the target: %d", a[middle]);
            printf("\n");
            return 0;
        }
        if(target < a[middle] ){
            upper = a[middle];
            if(middle == lower+1){
                middle = lower;
            }

        }else if(target > a[middle]){
            lower = a[middle];
            if(middle == upper -1){
                middle = upper;
            }
        }
    }
    return -1;
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    int b[1000000];
    create100000Array(b);
    int size = sizeof(b)/sizeof(b[0]);

    start = clock();
    linear_search(&b, 99999, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by linear_search: %f seconds\n", cpu_time_used);

    start = clock();
    binary_search(&b, 99999, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by binary_search: %f seconds\n", cpu_time_used);

    return 0;
}








