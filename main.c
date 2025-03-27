#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
//
//     *returnSize =2;
//     int* r = malloc(2 * sizeof(int));
//     //{2,7,11,15}
//     int i =0;
//     int e = numbersSize;
//     int start = numbers[i];
//     int end = numbers[e];
//     int j = 0;
//
//     while (j != e) {
//
//         if (start + end == target) {
//                 r[0] = i +1;
//                 r[1] = e +1;
//             return r;
//         }
//
//         if (end > target) {
//             end = numbers[e -= 1];
//         }else if (start + end > target) {
//             start = numbers[+1];
//             end = numbers[e -=1];
//         }
//         j++;
//     }
//     return 0;
//
// }
//
// char *get_temperature_status(int temp){
//     if(temp > 90){
//         printf("too hot");
//     }else if(temp < 70){
//         printf("too cold");
//     }else{
//         printf("just right");
//     }
// }
//
// struct Coordinate {
//     int x;
//     int y;
//     int z;
// };
//
// struct Coordinate new_coord(int x, int y, int z) {
//     struct Coordinate c = {
//         .x = x,
//         .y = y,
//         .z = z
//     };
//     return c;
// }

// bool isValid(char* s) {
//     char* stack[strlen(s)];
//     int top = -1;
//     for (int i = 0; s[i] != '\0'; i++) {
//         printf("%s",s);
//
//         if (s[i] == '('|| s[i] == '{' || s[i] == '[' ) {
//              *stack[top] =  s[i];
//             top++;
//             printf("%s", stack[top]);
//         }
//     }
// }


typedef struct num{
    int x;
    int y;
    int z;
}num1;

// num1 num_123(num1* f, int new_num) {
//     num1 new_f = *f;
//     printf("%p",new_f);
//     // printf("%d", (*f).x);
//     // printf("%d", (*f).y);
//     // (*f).x = new_num;
//     // return *f;
// }

void concat_strings(char *str1, const char *str2) {
  //iterate over str1 until we find '/O'

    int a = 0;
    for(int i = 0; str1[i] != '\0'; i++) {
        a++;
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        str1[a+i] = str2[i];
    }
}


int main() {
  char str1[100] = "Hello ";
  const char *str2 = "World";
  concat_strings(str1, str2);
    return 0;
}





