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

typedef struct Token {
    char* literal;
    int line;
    int column;
} token_t;

token_t** create_token_pointer_array(token_t* tokens, size_t count);

int main() {
    token_t tokens[3] = {
        {"foo", 1, 1},
        {"bar", 2, 5},
        {"baz", 3, 10}
    };
    token_t** result = create_token_pointer_array(tokens, 3);
    for (int i = 0; i < 3; i++) {
        printf("%s", result[i]->literal);
        printf("%s", tokens[i].literal);
        puts("end");
    }
    return 0;
}


token_t** create_token_pointer_array(token_t* tokens, size_t count) {
    token_t **token_pointers = malloc(count * sizeof(token_t*));


    if (token_pointers == NULL) {
        exit(1);
    }
    for (int i=0; i< count; i++) {
        token_t *p = (token_t*)malloc(sizeof(token_t)* count);
        //assigen my pointer-pointer to my pointer that points to the heap
        token_pointers[i] = &p[i];
        //take my pointer that points to the heap, dereferance it and copy obver the values of token
        *(p + i) = *(tokens+i);
    }
    return token_pointers;
}


