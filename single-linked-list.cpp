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

//get length using iterative method
int getLenth (Node* head){
    int count = 0;
    while(head) {
        head = head->next;
        count++;
    }
    return count;
}

//get length using recursive method
int _getLength(Node* head){
    if (head == nullptr) return 0;
    return 1 + _getLength(head->next);
}

// get middle node
//if even => then last one
int getMiddle(Node* head){
    Node *slowPtr = head, *fastPtr = head;
    if(head->next){
        while(fastPtr != nullptr and fastPtr->next != nullptr){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
    }
    return slowPtr->data;
}

//search element using iterative
int searchElement(Node* head, int key){
    if(!head) throw("list is empty");
    while(head){
        if(key == head->data){
            return head->data;
        }
        head = head->next;
    }
    throw("key doesn't exist");
}

bool _searchElement(Node* head, int key){
    if(!head) return false;
    if(head->data == key) return true;
    return _searchElement(head->next,key);
}

//simple method -> len-N+1
void getNthNodeFromEnd(Node* head, int n){
    if(!head){
        cout << "list is empty"<< endl;
        return;
    }

    int len = getLenth(head);
    if(n > len){
        cout << "nth value is greater than length"<< endl;
        return;
    }
    for(int i=1;i < len-n+1;i++){
        head = head->next;
    }
    cout<< "value at "<< n << " th from end node is: "<< head->data<< endl;
}

// search nth from end using recursive
void _getNthNodeFromEnd(Node* head, int n){
    static int i=0;
    if(!head) return;
    _getNthNodeFromEnd(head->next, n);
    if(++i == n){
        printf("value at %d th from end node is: %d", n, head->data);
    }
}

// search nth from end using two pointer
void __getNthNodeFromEnd(Node* head, int n){
    Node* mast = head, *ref= head;

    for(int i=0; i< n; i++){
        if(mast == nullptr) return;
        mast = mast->next;
    }

    while(mast != nullptr){
        mast = mast->next;
        ref = ref->next;
    }

    printf("value at %d th from end node is: %d", n, ref->data);
}

int main(){
    Node* head = nullptr;
    head = insertAtBeginning(head,4);
//    head = insertAtBeginning(head,5);
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 2);
//    head = insertAtEnd(head, 5);
//    head = insertAtEnd(head, 6);
    __getNthNodeFromEnd(head, 4);
//    _getNthNodeFromEnd(head,2);
//    cout << _searchElement(head, -1);
//    try{
//        cout << searchElement(head, 11);
//    }catch(const char* msg){
//        cerr << msg;
//    }
//    head = insertAtEnd(head, 10);
//    head = insertAt(head,5,15);
//    deletionFromBeginning(&head);
//    head = deletionFromEnd(head);
//    head = deletionFrom(head, 10);
//    try {
//        int data = fetchData(head,-5);
//        cout << data << endl;
//    }catch (const char* msg){
//        cerr << msg << endl;
//    }
//    print(head);
//    cout << getLenth(head) << endl;
//    cout << getMiddle(head) << endl;
//    cout << _getLength(head) << endl;

    return 0;
}