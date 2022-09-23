//
// Created by react-rajan on 9/21/22.
//

//sum of linked list
//2->4->7->1
//9->4->5
//
//list1 = 1742
//list2 = 549
//list1+list2 = 2291
//output 1->9->2->2
#include<iostream>
using namespace std;

class LinkedList {
public:
    int value;
    LinkedList *next = nullptr;

    LinkedList(int value) { this->value = value; }
};


void push(struct LinkedList** head_ref, int new_data)
{
    LinkedList* new_node = new LinkedList(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void print(LinkedList* head){
    while(head != nullptr){
        printf(" %d ", head->value);
        head = head->next;
    }
    cout<< endl;
}

LinkedList* insertAtEnd(LinkedList* head, int data){
    LinkedList* temp = new LinkedList(data), *ptr= head;
    if(!head){
        temp->next = ptr;
        head = temp;
    }else{
        while(ptr->next){
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->next = nullptr;
    }
    return head;
}

LinkedList *sumOfLinkedLists(LinkedList *linkedListOne,
                             LinkedList *linkedListTwo) {
    // Write your code here.
    LinkedList* list3 = nullptr;
    int list1Value = 0, list2Value = 0, result = 0;
    int i = 1;
    while(linkedListOne){
        list1Value = ((linkedListOne->value)*i) + list1Value;
        i *= 10;
        linkedListOne = linkedListOne->next;
    }
    i=1;
    while(linkedListTwo){
        list2Value = ((linkedListTwo->value)*i) + list2Value;
        i *= 10;
        linkedListTwo = linkedListTwo->next;
    }

    result = list1Value + list2Value;
    if(result > 0){
        while(result > 0){
            list3 = insertAtEnd(list3, result%10);
            result /= 10;
        }
    }else{
        list3 = insertAtEnd(list3, result%10);
    }


    return list3;
}

int main(){
    LinkedList* head = nullptr;
    push(&head, 0);

    print(head);
    LinkedList* head2 = nullptr;
//    push(&head2,5);
//    push(&head2,4);
    push(&head2,0);
    print(head2);
    LinkedList* head3 = nullptr;
    head3 = sumOfLinkedLists(head, head2);
    print(head3);
    return 0;
}