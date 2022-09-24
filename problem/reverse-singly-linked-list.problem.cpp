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

//reverse linked list using iterative method
void reserve(Node** head){
    Node *prev = nullptr, *next = nullptr, *current = *head;
    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void print(Node* head){
    while(head != nullptr){
        printf(" %d ", head->data);
        head = head->next;
    }
    cout<< endl;
}

//solution 02) using by recursion
Node* __reverse(Node* head)
{
    if (head == nullptr || head->next == nullptr) return head;

    Node* rest = __reverse(head->next);
    head->next->next = head;

    head->next = nullptr;

    return rest;
}

int main(){
    struct Node* head = nullptr;
    push(&head, 1);
    push(&head, 20);
    push(&head, 21);
    push(&head, 11);
    print(head);
    reserve(&head);
    print(head);
    head = __reverse(head);
    return 0;
}