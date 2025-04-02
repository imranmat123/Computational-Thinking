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

int main() {
    sel_weapon a = {.weaponType = STRING_SCROLL, .weapon  = "str+5" };
    print_weapon(&a);
    return 0;
}
void print_weapon(sel_weapon* s) {
    switch (s->weaponType) {
        case STRING_SCROLL:
            printf("woah you have the scroll of %s, that is super cool!",s->weapon.scroll);
        break;
        case INT_DAMAGE:
            printf("WOAH! now thats a lotta dmage: %d", s->weapon.damage);
        break;
        case FLOAT_HEALING:
            printf("You were just critted my G, now time to heal: %f", s->weapon.healing);
        break;
    }
}


