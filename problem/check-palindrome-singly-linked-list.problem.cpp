//
// Created by rajan on 9/20/22.
//

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data, int* count)
{
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*count)++;
    (*head_ref) = new_node;
}

// solution 1) using array as a stack and comparing values
bool checkPalindrome(Node* head, int* count){
    int *arr = (int*) malloc((*count)* sizeof(int));
    Node* temp = head;
    int i = 0;
    while(temp){
        *(arr + i) = temp->data;
        temp = temp->next;
        i++;
    }
    while(*count > 0){
        if(*(arr + *count -1) != head->data) return false;
        head = head->next;
        (*count)--;
    }
    return true;
}

void reverse(struct Node** head_ref)
{
    struct Node* prev = nullptr;
    struct Node* current = *head_ref;
    struct Node* next;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

bool compareLists(struct Node* head1, struct Node* head2)
{
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;

    while (temp1 && temp2)
    {
        if (temp1->data == temp2->data)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else return false;
    }
    // Both are empty return 1
    if (temp1 == nullptr) return true;
    return false;
}

//solution 2) using midpoint such as slow_ptr += 1 and fast_ptr += 2
bool isPalindrome(Node* head){
    struct Node *slow_ptr = head, *fast_ptr = head;
    struct Node *second_half, *prev_of_slow_ptr = head;
    struct Node* midnode = nullptr;
    bool res = true;

    if(!head || !(head->next)) return res;
    while (fast_ptr != nullptr && fast_ptr->next != nullptr)
    {
        fast_ptr = fast_ptr->next->next;
        prev_of_slow_ptr = slow_ptr;
        slow_ptr = slow_ptr->next;
    }
    if (fast_ptr != nullptr)
    {
        midnode = slow_ptr;
        slow_ptr = slow_ptr->next;
    }
    second_half = slow_ptr;
    prev_of_slow_ptr->next = nullptr;

    // Reverse the second half
    reverse(&second_half);

    // compare
    res = compareLists(head, second_half);

    // Construct the original list back
    reverse(&second_half); // Reverse the second half again

    if (midnode != nullptr)
    {
        prev_of_slow_ptr->next = midnode;
        midnode->next = second_half;
    }
    else prev_of_slow_ptr->next = second_half;

    return res;
}

void print(Node* head){
    while(head != nullptr){
        printf(" %d ", head->data);
        head = head->next;
    }
    cout<< endl;
}

int main(){
    struct Node* head = nullptr;
    int count = 0;
    push(&head, 1, &count);
//    push(&head, 2, &count);
//    push(&head, 3, &count);
//    push(&head, 2, &count);
//    push(&head, 1, &count);
    print(head);
//    cout << count;
//    cout << checkPalindrome(head, &count);
    cout << isPalindrome(head) << endl;
    print(head);
}
