//
// Created by rajan khadka on 20/09/2022.
//

#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void print(Node* head){
    while(head != nullptr){
        printf(" %d ", head->data);
        head = head->next;
    }
    cout<< endl;
}




//solution 01) using two loops time O(n^2) space O(1)
Node* removeDuplicate(Node* head){
    Node *ptr1 = head, *ptr2, *dup;

    while(ptr1 && ptr1->next){
        ptr2 = ptr1;
        while(ptr2->next){
            if(ptr1->data == ptr2->next->data){
                dup = ptr2->next;
                ptr2->next = dup->next;
                free(dup);
            }else{
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
    return head;
}

void removeKthNodeFromEnd(Node *head, int k) {
    // Write your code here.
    Node *mast= head, *ref=head, *prev= nullptr;
    for(int i=0;i<k;i++){
        if(!mast) return;
        mast = mast->next;
    }

    while(mast){
        prev = ref;
        mast=mast->next;
        ref=ref->next;
    }
    if(prev != nullptr){
        prev->next = ref->next;
        free(ref);
    }else{
        head->data = ref->next->data;
        head->next = ref->next->next;
//        free(ref);
    }
//
}

int main(){
    struct Node* head = nullptr;
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
//    push(&head, 1);
//    push(&head, 0);
    print(head);
    removeKthNodeFromEnd(head, 3);
    print(head);
//    head = removeDuplicate(head);
//    print(head);
//    push(&head, 21);
//    push(&head, 21);
//    push(&head, 11);
    return 0;
}