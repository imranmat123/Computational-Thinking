#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

void insert(int a[], int *e, int val){
    a[*e] = val;
    (*e)++;
}

int removeDuplicates(int* nums, int numsSize) {
 int *a = nums;
 int aSize = numsSize;
 int b[aSize];
 int i = 1;
 int e = 1;
 b[0] = a[0];

while(i < aSize){
    int t = a[i-1];
    if(t != a[i]){
        insert(b,&e,a[i]);
    }
    i++;
}
int c[e];
int j=0;
while(j<e){
    c[j] = b[j];
    j++;
}

    return *c;
}

int main() {


    // Input array (sorted array with duplicates)
    int nums[] = {1, 1, 2, 2, 3, 4, 4, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    // Expected array after duplicates are removed
    int expectedNums[] = {1, 2, 3, 4, 5};
    int expectedSize = sizeof(expectedNums) / sizeof(expectedNums[0]);

    // Call your function
    int k = removeDuplicates(nums, numsSize);


    // Test that the first k elements match the expected array
    for (int i = 0; i < k; i++) {
        assert(nums[i] == expectedNums[i]);
    }

    printf("All tests passed! k = %d\n", k);
    return 0;
}




