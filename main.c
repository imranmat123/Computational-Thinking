#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 10

struct stack{
    int arr[MAX_SIZE];
    int top;
};

int push(struct stack *stack, int value){
    if (stack->top == MAX_SIZE-1){
        printf("stack is full, cannot add more");
    }else{
        stack->top = stack->top +1;
        stack->arr[stack->top] = value;
    }
    return stack->arr[stack->top];

}

int pop(struct stack *stack){
    int popped;
    if(stack->top == 0){
        printf("there is nothing in the array");
        return -1;
    }else{
        popped = stack->arr[stack->top -1];
        stack->top = stack->top -1;
    }
    return popped;
}

int TopVal(struct stack *stack){
    if(stack->top == 0){
        printf("there is nothing in the array");
        return -1;
    }else{
        return stack->arr[stack->top-1];
    }
}

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
stack->top = -1;
int val = 0;
bool found = false;
for(int i = 0; i < nums1Size; i++){
    found = false;
    int x = nums1[i];
    for(int j = 0; j< nums2Size; j++){
        int y = nums2[j];
        if(x == y){
            val = nums2[j];
            for(int d = j+1; d < nums2Size; d++ ){
                if(val < nums2[d]){
                    int m = nums2[d];
                    push(stack, m);
                    found = true;
                    break;
                }
            }
            if(found == false){
                push(stack, -1);
            }
            break;
        }
    }
}
    int *results = malloc(nums1Size * sizeof(int));
    for(int q = nums1Size - 1; q >= 0; q--){
        results[q] = stack->arr[q];
    }

    *returnSize = nums1Size;
    return results;
}

int main(void) {
    // Test case: Example 1
    int nums1[] = {4, 1, 2};
    int nums2[] = {1, 3, 4, 2};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize = 0;

    int* result = nextGreaterElement(nums1, nums1Size, nums2, nums2Size, &returnSize);

    // Print the result array.
    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    free(result);
    return 0;
}




