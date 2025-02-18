#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}

typedef struct node node;
struct node {
    int data;
    node* next;
};

node* CreateHead(int data){
    node* a = (node *) malloc( sizeof(node));
    a->data = data;
    a->next = NULL;
    return a;
}

node* insertAtBeginning (node* current_head,int data){
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = current_head;
    return new_node;
}

node* insertAtEnd(node* current_head, int data){
    node* a = (node*) malloc(sizeof(node));
    a->data = data;
    a->next = NULL;
    node* tempHead = current_head;
    while(tempHead->next != NULL){
        tempHead = tempHead->next;
        if (tempHead->next == NULL){
            tempHead->next = a;
        }
    }
    return a;
}

node* traverseList(node* current_head, int data){
    node* temp = current_head;
    while (temp != NULL){
        if(temp->data == data){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

node* deleteNode(node* head, int delete){
    node* prev = head;
    node* curr = head->next;

    if(prev->data == delete){
        free(prev);
        prev = curr;
        curr = curr->next;
    }
    while(curr != NULL){
        if(curr->data == delete){
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        } else{
            prev = prev->next;
            curr = curr->next;
        }
    }
    return prev;

}


