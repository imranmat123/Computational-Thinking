#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int heapifiy(int* a, int arraysize){
    int loop = arraysize;

    int parent = arraysize/2;
    while(loop != 0){
        int leftLeaf = parent *2 +1;
        int rightLeaft = parent *2 +2;

        if(rightLeaft < arraysize){
            if(a[rightLeaft] > a[parent]){
                int temp = a[parent];
                a[parent] = a[rightLeaft];
                a[rightLeaft] = temp;
            }
        }
        if(leftLeaf < arraysize){
            if(a[leftLeaf] > a[parent]){
                int temp = a[parent];
                a[parent] = a[leftLeaf];
                a[leftLeaf] = temp;
            }
        }

        if(parent == 0){
            parent = arraysize/2;
        }
        parent--;
        loop--;
    }

    return 0;
}


int main() {
    // Define an example array
    int testArray[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int arraySize = sizeof(testArray) / sizeof(testArray[0]);

    // Print the array before heapify
    printf("Array before heapify:\n");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", testArray[i]);
    }
    printf("\n");


    // Call your heapify function
        heapifiy(testArray, arraySize);


    // Print the array after heapify
    printf("Array after heapify:\n");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", testArray[i]);
    }
    printf("\n");

    return 0;
}




