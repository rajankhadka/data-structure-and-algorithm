//
// Created by rajan khadka on 21/09/2022.
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


Node* findLoop(Node* head){
    Node *slowptr = head, *fastptr = head, *temp = nullptr;
    bool flag = false;
    if(!head) return nullptr;

    while(fastptr && fastptr->next){
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        if(slowptr == fastptr){
            slowptr = head;
            flag = true;
            break;
        }
    }
    if(flag){
        while(fastptr != slowptr){
            fastptr = fastptr->next;
            slowptr = slowptr->next;
        }
        temp = fastptr;
        return temp;
    }
    return nullptr;
}

int main() {
    struct Node *head = nullptr;
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    head->next->next->next->next->next->next->next->next->next = head->next->next->next->next;

    head = findLoop(head);
    print(head);
    return 0;
}
