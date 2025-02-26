#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

void createNode(struct Node** tree, int value){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->right = NULL;
    node->left = NULL;

    //if tree data is null, than set left and right pointers to null as you are head,
    if(*tree == NULL){
        *tree = node;
        return;
    }
    struct Node* head = *tree;
    struct Node* next = head;

    while(next != NULL ){
        head = next;
        if(node->data > next->data ){
            next = head->right;
        }else if(node->data < next->data){
            next = head->left;
        }
    }
    if(node->data > head->data){
        head->right = node;
    }else if(node->data < head->data){
        head->left = node;
    }else if(node->data == head->data){
        free(node);
        return;
    }
    }


int searchTree(struct Node* tree, int value){
    struct Node* head = tree;
    while(head != NULL){
    if(head->data == value){
        return head->data;
    }else if(value > head->data){
        head = head->right;
    } else if(value < head->data){
        head = head->left;
    }
        return -1;
    }

}

int main(void) {
    return 0;
}




