#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct SnekObject snek_object_t;

typedef struct {
    size_t size;
    snek_object_t **elements;
} snek_array_t;

typedef struct {
    snek_object_t *x;
    snek_object_t *y;
    snek_object_t *z;
} snek_vector_t;

typedef enum SnekObjectKind {
    INTEGER,
    FLOAT,
    STRING,
    VECTOR3,
    ARRAY,
  } snek_object_kind_t;

typedef union SnekObjectData {
    int v_int;
    float v_float;
    char *v_string;
    snek_vector_t v_vector3;
    snek_array_t v_array;
} snek_object_data_t;

typedef struct SnekObject {
    snek_object_kind_t kind;
    snek_object_data_t data;
} snek_object_t;

snek_object_t *new_snek_integer(int value);
snek_object_t *new_snek_float(float value);
snek_object_t *new_snek_string(char *value);
snek_object_t *new_snek_vector3(
    snek_object_t *x, snek_object_t *y, snek_object_t *z
);
snek_object_t *new_snek_array(size_t size);
bool snek_array_set(snek_object_t *array, size_t index, snek_object_t *value);
snek_object_t *snek_array_get(snek_object_t *array, size_t index);
snek_object_t *snek_add(snek_object_t *a, snek_object_t *b);

int main() {

    snek_object_t *one = new_snek_integer(1);
    snek_object_t *ones = new_snek_array(2);
    //both 1
    snek_array_set(ones, 0, one);
    snek_array_set(ones, 1, one);

    snek_object_t *hi = new_snek_string("hi");
    snek_object_t *hellos = new_snek_array(3);
    //all hi
   snek_array_set(hellos, 0, hi);
   snek_array_set(hellos, 1, hi);
   snek_array_set(hellos, 2, hi);

    snek_object_t *result = snek_add(ones, hellos);






    return 0;
}

snek_object_t *new_snek_array(size_t size) {
    snek_object_t* sObject =  malloc(sizeof(snek_object_t));
    if(sObject ==  NULL){
        return NULL;
    }
    snek_object_t** sPointer = calloc(size, sizeof(snek_object_t*));
    if(sPointer == NULL){
        free(sPointer);
        return NULL;
    }
    sObject->kind = ARRAY;
    snek_array_t newArray =  {.size = size, .elements = sPointer};
    sObject->data.v_array = newArray;

    return sObject;
    // ?
}


snek_object_t *new_snek_vector3(snek_object_t *x, snek_object_t *y, snek_object_t *z) {
    if(x == NULL |y==NULL| z==NULL){
        return NULL;
    }
    snek_object_t*  v = malloc(sizeof(snek_object_t));
    if(v == NULL){
        return NULL;
    }
    v->kind = VECTOR3;
    snek_vector_t v1 = {.x = x, .y = y,.z = z};

    v->data.v_vector3 = v1;
    return v;

    // ?
}

bool snek_array_set(snek_object_t *snek_obj, size_t index, snek_object_t *value) {
    if(snek_obj == NULL){
        return false;
    }
    if(snek_obj->kind != ARRAY){
        return false;
    }
    if(index > snek_obj->data.v_array.size){
        return false;
    }
    snek_obj->data.v_array.elements[index] = value;
    return true;
}
snek_object_t *snek_array_get(snek_object_t *snek_obj, size_t index) {
    if(snek_obj == NULL){
        return NULL;
    }
    if(snek_obj->kind != ARRAY){
        return NULL;
    }
    if(index > snek_obj->data.v_array.size){
        return NULL;
    }
    return snek_obj->data.v_array.elements[index];
    // ?
}

int snek_length(snek_object_t *obj) {
    if(obj == NULL){
        return -1;
    }
    if(obj->kind == INTEGER){
        return 1;
    }
    if(obj->kind == FLOAT){
        return 1;
    }
    if(obj->kind == STRING){
        return strlen(obj->data.v_string);
    }
    if(obj->kind == VECTOR3){
        return 3;
    }
    if(obj->kind == ARRAY){
        return obj->data.v_array.size;
    }
    return -1;

    // ?
}

snek_object_t *new_snek_float(float value) {
    snek_object_t* f = malloc(sizeof(snek_object_t));
    if(f == NULL){
        free(f);
        return NULL;
    }
    f->kind = FLOAT;
    f->data.v_float = value;
    return f;
}

snek_object_t *new_snek_string(char *value) {
    snek_object_t* s = malloc(sizeof(snek_object_t));
    if(s == NULL){
        return NULL;
    }
    int l = strlen(value) +1;
    char* stringHeap = malloc(sizeof(char) * l);
    if(stringHeap == NULL){
        free(stringHeap);
        return NULL;
    }
    strcpy(stringHeap, value);
    s->kind = STRING;
    s->data.v_string = stringHeap;

    return s;
    // ?
}
snek_object_t *new_snek_integer(int value) {
    snek_object_t* o = malloc(sizeof(snek_object_t));
    if(o == NULL){
        return NULL;
    }
    o->kind = INTEGER;
    o->data.v_int = value;
    return o;

    // ?
}

snek_object_t *snek_add(snek_object_t *a, snek_object_t *b) {
    if(a == NULL || b == NULL){
        return NULL;
    }

    if(a->kind == INTEGER){
        if(b->kind == INTEGER){
            int ints = a->data.v_int + b->data.v_int;
            return new_snek_integer(ints);
        }
        return NULL;
    }
    if(a->kind == FLOAT){
        if(b->kind == FLOAT){
            float f = a->data.v_float + b->data.v_float;
            return new_snek_float(f);
        }
        return NULL;
    }
    if(a->kind == STRING){
        if(b->kind != STRING){
            return NULL;
        }
    int l = strlen(a->data.v_string) + strlen(b->data.v_string) +1;
        //pointer to string on heap
        char* newString = calloc(l, sizeof(char));
        //dereferance the pointer to allow for concat
        strcat(newString,a->data.v_string);
        strcat(newString,b->data.v_string);
        //create a varible that returns a value;
        snek_object_t *newerString = new_snek_string(newString);
        free(newString);
        return newerString;
    }
    if (a->kind == VECTOR3) {
        if (b->kind != VECTOR3) {
            return NULL;
        }
        return new_snek_vector3(snek_add(a->data.v_vector3.x,b->data.v_vector3.x),snek_add(a->data.v_vector3.y,b->data.v_vector3.y),snek_add(a->data.v_vector3.z,b->data.v_vector3.z));
    }
    if (a->kind == ARRAY) {
        if(b->kind != ARRAY){
            return NULL;
        }
        int size = a->data.v_array.size + b->data.v_array.size;
        snek_object_t *newArray = new_snek_array(size);
        int j =0;
        for (int i = 0; i <= a->data.v_array.size -1; i++) {
            snek_array_set(newArray,j,snek_array_get(a, i));
            j++;
        }
        for (int i = 0; i <= b->data.v_array.size -1; i++) {
            snek_array_set(newArray,j,snek_array_get(b, j));
            j++;
        }
        return newArray;
    }
    return NULL;
    // ?
}

