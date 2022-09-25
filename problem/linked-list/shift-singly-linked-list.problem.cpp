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

Node* shiftList(Node* head, int shift){
    Node* oldHead = head, *oldTail = nullptr, *newHead = nullptr, *newTail = nullptr, *ptr = head;
    if(!head || !head->next || shift ==0) return head;
    int length = 0;

    //first find old tail and length
    while(ptr){
        if(!ptr->next) oldTail = ptr;
        ptr= ptr->next;
        length++;
    }

    if(shift >= length) shift = shift % length;

    if(shift < 0){
        shift = shift * (-1);
        length = shift >= length ? shift % length : shift;
    }else{
        length = length - shift;
    }
    ptr = head;
    //find new tail and new head
    while(length){
        if(length == 1) {
            newTail = ptr;
            newHead = ptr->next;
        }
        ptr = ptr->next;
        length--;
    }
    //merge them all
    if(newHead && newTail){
        oldTail->next = oldHead;
        newTail->next = nullptr;
        head = newHead;
    }
    return head;
}

int main(){
    struct Node* list1 = nullptr;
    push(&list1, 5);
    push(&list1, 4);
    push(&list1, 3);
    push(&list1, 2);
    push(&list1, 1);
    push(&list1, 0);
    print(list1);
    list1 = shiftList(list1, -7);
    print(list1);
    return 0;
}