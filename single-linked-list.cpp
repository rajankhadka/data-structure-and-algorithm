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
        ptr->next = temp;
    }
    return head;
}

void deletionFromBeginning(Node** head){
    if(*head == nullptr){
        cout << "Head is empty" << endl;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}


Node* deletionFromEnd(Node* head){
    if(!head->next){
        cout<< "List is Empty"<< endl;
        return head;
    }

    Node* prev = head;
    Node* ptr = head;
    //traverse to the end;
    while(ptr->next){
        prev = ptr;
        ptr = ptr->next;
    }

    prev->next = nullptr;
    free(ptr);
    return head;
}

Node* deletionFrom(Node* head, int index){
    if(!head->next){
        cout << "List is Empty";
        return head;
    }

    if(index == 0) {
        deletionFromBeginning(&head);
        return head;
    }

    Node* temp = head;
    Node* prev = head;
    while(temp->next && index > 0){
        prev = temp;
        temp = temp->next;
        index--;
    }
    if(index == 0){
        prev->next = temp->next;
        temp->next = nullptr;
        free(temp);
    }else{
        prev->next = nullptr;
        free(temp);
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

//fetch node at particular
int fetchData(Node* head, int index){
    if(!head->next || index < 0) throw "index out of bound min";
    if(index == 0) return head->data;
    while(head->next && index>0){
        head = head->next;
        index--;
    }
    if(index == 0) return head->data;
    throw "index out of bound max";
}

int getLenth (Node* head){
    int count = 0;
    while(head) {
        head = head->next;
        count++;
    }
    return count;

}

int main(){
    Node* head = nullptr;
    head = insertAtBeginning(head,4);
    head = insertAtBeginning(head,4);
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 10);
    head = insertAt(head,5,15);
//    deletionFromBeginning(&head);
//    head = deletionFromEnd(head);
//    head = deletionFrom(head, 10);
    try {
        int data = fetchData(head,-5);
        cout << data << endl;
    }catch (const char* msg){
        cerr << msg << endl;
    }
    print(head);
    cout << getLenth(head) << endl;
    return 0;
}