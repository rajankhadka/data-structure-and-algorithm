//
// Created by react-rajan on 9/23/22.
//

//problem merge two singly linked list
// must be on sorted order
//list1 = 1 3 5 7 9
//list2 = 4 6 8
//list3 = 1 3 4 6 7 8 9
//but there should not be exactly list, but mutated one of the input list (list1 or list2)
// time O(m+n) m= length of list1, n= length of list2 , space O(1)
//using iterative method
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

Node* mergeList(Node* list1, Node* list2){
    Node* prev = nullptr, *head = nullptr;

    while(list1 && list2){
        if(list1->data < list2->data){
            if(prev){
                prev->next = list1;
                prev = list1;
                list1 = list1->next;
                prev->next = list2;
            }else{
                prev = list1;
                head = prev;
                list1 = list1->next;
                prev->next = list2;
            }
        }else{
            if(prev){
                prev->next = list2;
                prev=list2;
                list2 = list2->next;
                prev->next = list1;
            }else{
                prev = list2;
                head = prev;
                list2 = list2->next;
                prev->next = list1;
            }
        }
    }

    if(list1){
        prev->next = list1;
    }else{
        prev->next = list2;
    }
    return head;
}


//another method
Node* _mergeList(Node *list1, Node* list2){
    Node* p1 = list1, *p2 = list2, *p1Prev= nullptr;
    while(p1 && p2){
        if(p1->data < p2->data){
            p1Prev = p1;
            p1 = p1->next;
        }else{
            if(p1Prev)
                p1Prev->next = p2;
            p1Prev = p2;
            p2 = p2->next;
            p1Prev->next = p1;
        }
    }
    if(p1)
        p1Prev->next = p2;
    
    return list1->data < list2->data ? list1 : list2;
}

int main(){
    struct Node* list1 = nullptr, *list2 = nullptr;
    push(&list1, 9);
    push(&list1, 7);
    push(&list1, 5);
    push(&list1, 3);
    push(&list1, 2);
    print(list1);

    push(&list2, 8);
    push(&list2, 6);
    push(&list2, 1);
//    push(&list2, 3);
    print(list2);
    list1 = mergeList(list1, list2);
    print(list1);
    return 0;
}