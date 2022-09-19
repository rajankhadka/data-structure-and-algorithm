//
// Created by rajan on 9/19/22.
// implementation of singly linked list using struct
//
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* createNode(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

//insert at beginning time complexity O(1)
Node* insertAtBeginning( Node* head,int data){
    Node* temp = createNode(data);
    temp->next = head;
    head = temp;
    return head;
}

//insert at end time complexity O(n)
Node* insertAtEnd(Node* head, int data){
    Node *temp= createNode(data), *ptr = head;
    if(head == nullptr) return insertAtBeginning(head,data);

    while(ptr->next != nullptr){
        ptr = ptr->next;
    }
    ptr->next = temp;
    return head;

}

//insert at somewhere time complexity O(n)
Node* insertAt(Node* head, int data, int index){
    Node *temp = createNode(data), *ptr = head, *prev = head;
    if(head == nullptr || index == 0) return insertAtBeginning(head,data);


    while(ptr->next != nullptr && index > 0){
        prev = ptr;
        ptr = ptr->next;
        index--;
    }
    if(index == 0){
        prev->next = temp;
        temp->next = ptr;
    }else{
        return insertAtEnd(head,data);
    }
    return head;
}

//display time complexity O(n)
void print(Node* head){
    while(head != nullptr){
        printf(" %d ", head->data);
        head = head->next;
    }
    cout<< endl;
}

int main(){
    Node* head = nullptr;
    head = insertAtBeginning(head,4);
    head = insertAtBeginning(head,4);
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 10);
    head = insertAt(head,5,10);
    print(head);

    return 0;
}