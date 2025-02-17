#include <stdio.h>

int main(void) {
    int arr[] = {1, 2, 3, 4, 6};
    int l = sizeof(arr)/ sizeof(arr[0]);


    int a = arr[0];
    int b = arr[0];

    for(int i = 0; i <= l -1; i++){
        if(a >= arr[i]){
            a = arr[i];
        }
        if(b <= arr[i]){
            b = arr[i];
        }
    }
    printf("%d\n", a);
    printf("%d\n", b);

    for(int j = 0; j <= l-1; j++){
        while(j <= l){
            if(a != arr[j]){
                printf("%d",a);
            }
            a++;
            break;
        }
    }

    return 0;
}
