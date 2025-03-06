#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node{
    char* key;
    char* value;
    struct node* next;
};

void setNode(struct node* node, char* key, char* value){
    node->key = key;
    node->value = value
    node->next = NULL;
    return;
}

struct hashMap{
    int size, eleNUmber;
    struct node** arr;
};

void initizseHashMap(struct hashMap* nash){
    nash->size = 100;
    nash->eleNUmber=0;
    nash->arr = (struct node**)malloc(sizeof(node*) * size);
    return;
}

int hashFunction(struct hashMap* hash, char* value){
    //get length of string =a,
    int a = strlen(value);
    // empty int actualIndex = 0
    int actualIndex = 0;
    //empty varible that holds ints for anki addup = sum
    int sum = 0;
    for(int i = 0; i =< a-1; i++){
        //1, get the first char = b
        //2, get aski values of that char
        int ascii = (int)value[i];
        //3, add that value to sum,
        sum = sum + ascii;
        //4, a--
    }
    //5, do 1,2,3,4 while a !=0;
    actualIndex = sum % hash->size;
    // actualIndex = sum%hash->size
    return actualIndex;
    //return actualIndex
}

void insert(struct hashMap* hash, char* value){
    a = hashFunction(hash,value);
    node* b = (struct node*) malloc(sizeof(struct node));
    setNode(b,a,value);
    if(hash->arr[a] == NULL){
        hash->arr[a] = b;
    }else if(hash->arr[a] != NULL){
        b->next = arr[a];
        arr[a] = b;
    }
    return;
}

void delete(struct hashMap* hash, char* key){
    int a = hashFunction(hash, key);
    if (hash->arr[a] != NULL){

        struct node* head = hash->arr[a];
        struct node* next = head->next;

        //whilst head is not null
        while(head != NULL){
            //if head is equal to the value, set arr to next and free head
            if(strcmp(head->key, key) == 0){
                hash->arr[a] = next;
                //else if next value is equal to value, than set head's next value to nexts next value,
                //free next, and assign a the new value to next.
            }else if(next != NULL){
                if(strcmp(next->key, key) == 0){
                    head->next = next->next;
                    next = head->next;
                }
            }
            head = next;
            next = head->next;
        }
    }
    return;
}

int main() {

    return 0;
}




