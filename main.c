#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef enum WeaponType {
    STRING_SCROLL,
    INT_DAMAGE,
    FLOAT_HEALING,
}weapon_t;

typedef union weapon {
    char scroll[20];
    int damage;
    float healing;
}one_weapon;

typedef struct SelectedWeapon {
    weapon_t weaponType;
    one_weapon weapon;
}sel_weapon;

void print_weapon(sel_weapon *w);

char* get_full_greeting(char *greeting, char *name, int size);
int *allocate_scalar_list(int size, int multiplier);

int main() {
    int *result = allocate_scalar_list( 5, 1);

    for (int i =0; i<5;i++) {
        printf("%d\n",*(result+i) );
    }
    free(result);


    return 0;
}

int *allocate_scalar_list(int size, int multiplier) {
    int *malArray = (int* )malloc(size * sizeof(int));
    if(malArray == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }


    for(int i = 0; i<size;i++){
        malArray[i] = (i * multiplier);
    }

    return malArray;
    // ?
}


