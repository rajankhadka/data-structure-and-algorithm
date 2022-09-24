//
// Created by react-rajan on 9/20/22.
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

// when list is on sorted order
Node* removeDuplicate(Node* head){
    Node *nextptr = nullptr, *current = head;
    if(!current) return head;
    while(current->next){
        if(current->data == current->next->data){
            nextptr = current->next->next;
            free(current->next);
            current->next = nextptr;
        }else{
            current = current->next;
        }
    }
    return head;
}

int main(){
    struct Node* head = nullptr;
    push(&head, 1);
    push(&head, 20);
//    push(&head, 20);
//    push(&head, 20);
//    push(&head, 21);
//    push(&head, 21);
//    push(&head, 21);
//    push(&head, 11);
    head = removeDuplicate(head);
    print(head);
    return 0;
}