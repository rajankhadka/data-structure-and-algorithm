//
// Created by rajan on 9/20/22.
//
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node* next;
    bool flag;
};

void push(struct Node** head_ref, int new_data)
{
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->flag = false;
    (*head_ref) = new_node;
}

//detect loop in linked list
//solution 01) using hash map -> time = O(n), space = O(n)
bool detectLoop(Node* head){
    unordered_set<struct Node*> hash;
    while(head){
        if(hash.find(head) != hash.end() ) return true;
        hash.insert(head);
        head = head->next;
    }
    return false;
}

//solution 2) without hash map but storing additional field on linked list. time O(n), space 0(1)
bool _detectLoop(Node* head){
    while(head){
        if(head->flag) return true;
        head->flag = true;
        head = head->next;
    }
    return false;
}

//solution 3) floyd cycle finding algorithm
bool __detectLoop(Node* head){
    Node* slow_ptr = head, *fast_ptr = head;
    while(fast_ptr && fast_ptr->next){
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if(slow_ptr == fast_ptr) return true;
    }
    return false;
}

int main(){
    struct Node* head = nullptr;
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
//    push(&head, 10);

    head->next->next->next  = nullptr;
    cout << __detectLoop(head);
    return 0;
}