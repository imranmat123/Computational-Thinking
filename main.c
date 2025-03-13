#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct ListNode {
   int val;
   struct ListNode *next;
};


struct ListNode* createNode(int val){
    struct ListNode* new = (struct ListNode*) malloc(sizeof(struct ListNode));
    new->val = val;
    new->next = NULL;
    return new;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* a =  l1;
    struct ListNode* b =  l2;
    int times = 1;
    int sum1 = 0; int sum2 =0;
    //pointers for first list
    struct ListNode* head = a;
    //pointers for 2second list
    struct ListNode* headl2 = b;

    while(head != NULL && headl2 != NULL){
        if(head->val != 0){
            sum1 = sum1+(head->val * times);
            head = head->next;
        }

        if(headl2->val != 0){
            sum2 = sum2+(headl2->val * times);
            headl2 = headl2->next;
        }

        times = times * 10;
    }

    int r =10;
    int result = sum1+sum2;
    struct ListNode* c = (struct ListNode*) malloc(sizeof(struct ListNode));
    c = NULL;

    while(result > 0){
    struct ListNode* headl3 = c;
    struct ListNode* new = (struct ListNode*) malloc(sizeof(struct ListNode));
   if(c ==NULL){
       new->val = result % r;
       new->next = headl3;
       c = new;
   }else if(headl3 !=NULL){
            new->val = result % r;
            new->next = headl3;
            headl3 = new;
            c = headl3;
        }
        result = result/10;
    }
    return c;

}

void printList(struct ListNode* node) {
    while(node != NULL) {
        printf("%d -> ", node->val);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    // Create first linked list: 2 -> 4 -> 3
    struct ListNode* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);

    // Create second linked list: 5 -> 6 -> 4
    struct ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    printf("List 1: ");
    printList(l1);

    printf("List 2: ");
    printList(l2);

    // Call your addTwoNumbers function
    struct ListNode* result = addTwoNumbers(l1, l2);

    printf("Result: ");
    printList(result);

    return 0;
}








