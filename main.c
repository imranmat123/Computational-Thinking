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

typedef struct {
    size_t length;
    char buffer[64];
} TextBuffer;

int smart_append(TextBuffer* dest, const char* src) {
    // ?
    if(src == NULL || dest == NULL){
        return 1;
    }
    int constVar = 64;
    int length = strlen(src);
    int remaining = constVar - dest->length -1;
    if(length > remaining) {
        strncat(dest->buffer,src,remaining);
        dest->length = constVar -1;
        return 1;
    }
    strcat(dest->buffer,src);
    dest->length = length;
    return 0;
}



int main() {
TextBuffer dest;
strcpy(dest.buffer, "This is a very long string that will fill up the entire buffer.");
dest.length = 63;
const char* src = " Extra";
int result = smart_append(&dest, src);
    printf("%d", result);
    printf("%s", dest.buffer);
    printf("%zu",&dest.length);
    return 0;
}





