#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s) {
    int a = strlen(s);
    if (a % 2 != 0) {
        return false;
    }

    int aSize =  strlen(s)/2; //
    int top = -1;

    char e[aSize]; //array for the ending
    // formula for the top index + top
    for(int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            top++;
            e[top] = s[i];
        }

        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (e[top] == '(' && s[i] == ')' || e[top] == '{' && s[i] == '}' || e[top] == '[' && s[i] == ']') {
                top--;
            }

        }
    }

    if (top == -1) {
       return  true;
    }
       return false;
}


int main() {
    char* a = "(]";
    printf("%hhd", isValid(a));
    isValid(a);
    return 0;
}





