//
// Created by rajan khadka on 25/09/2022.
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


Node* rearrangeList(Node* head, int k){
    Node* small = nullptr, *equal = nullptr, *large = nullptr;

}

int main(){
    struct Node* list1 = nullptr;
    push(&list1, 4);
    push(&list1, 1);
    push(&list1, 2);
    push(&list1, 5);
    push(&list1, 0);
    push(&list1, 3);
    print(list1);
    return 0;
}