#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define LOWER  0
#define UPPER 300
#define STEP 20
float convertToC(float f){
  float c = (5.0/9.0) * (f-32.0) ;
  return c;
}

float convertToF(float c) {
    float f = c *9.0/5.0 + 32.0;
    return f;
}



int main() {
    puts("you will give me a newline?");
    printf("F to C %f\n", convertToC(100.00));
    printf("C to F %f\n", convertToF(100));

    float f = 0.0;
    float c = 0.0;
    float update = 0.0;

    //going in assending order
    do{
        printf("Converting Fah to Cel %2.0f ", convertToC(f));
        printf("Converting Cel to Fah %2.0f\n" , convertToF(c));

        update += STEP;
        c = update; f = update;
    }while(update < UPPER);

    //going in desending order

    puts("Desenidng order with a forloop:");
    for (update = UPPER; update > 0; update -= STEP) {
        c = update; f = update;
        printf("Converting C to F %2.0f ",convertToF(c));
        printf("Converting F to C %2.0f\n", convertToC(f));
    }
    return 0;
}








