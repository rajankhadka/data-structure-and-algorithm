//
// Created by rajan khadka on 25/09/2022.
//

//doubly linked list
#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

Node* insertAtHead(Node* head, int data){
    Node* temp = new Node;
    temp->data = data;
    temp->prev = nullptr;
    temp->next = head;
    if(head){
        head->prev = temp;
    }
    head = temp;
    return head;
}

int main(){
    Node *head = nullptr;
    head = insertAtHead(head,1);
    head = insertAtHead(head,2);
    head = insertAtHead(head,3);
}