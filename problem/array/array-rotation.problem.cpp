//
// Created by react-rajan on 10/17/22.
//
#include <iostream>

using namespace std;


//001) time O(n) and space O(n)
void rotate(int* arr,int length,int shift){
//    int *temp = (int*)malloc(length*sizeof(int));
    if(length == 0) return;
    shift = shift % length;
    if(shift == 0) return;
    int* temp = new int[length];
    int k=0;

    for(int i=shift;i<length;i++){
        temp[k++] = arr[i];
    }

    for(int i=0;i<shift;i++){
        temp[k++] = arr[i];
    }
    for(int i =0;i<length;i++){
        *(arr+i) = *(temp+i);
    }
    delete[] temp;
}

//002) by shifting element time O(n*d) and space O(1)
void _rotate(int *arr,int length, int shift){
    if(length == 0) return;
    shift = shift % length;
    if(shift == 0) return;
    while(shift>0){
        int insert = arr[0];
        for(int i=0;i<length-1;i++){
            arr[i] = arr[i+1];
        }
        arr[length-1] = insert;
        shift--;
    }
}


// 03) using juggling algorithm for left rotation time O(n) space O(1)
int gcdCalculate(int first, int second){
    if(second == 0) return first;
    return gcdCalculate(second, first%second);
}

void __rotate(int *arr, int length, int shift){
    if(length == 0) return;
    shift = shift % length;
    int gcd = gcdCalculate(length,shift);
    for(int i=0;i<gcd;i++){
        int j = i,temp = arr[i];
        while(true){
            int k = (j+shift) % length;
            if(k == i) break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

//004 using juggling algorithm for right rotation time O(n) space O(1)
void ___rotate(int *arr, int length,int shift){
    shift = length - (shift%length);
    int gcd = gcdCalculate(length,shift);
    for(int i=0;i<gcd;i++){
        int temp = arr[length-i-1], j = length-i-1;
        while(true){
            int k = (j+shift) % length;
            if(k == length-i-1) break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

//005) reversal algorithm for left rotation space O(1) and time O(n)
void reverse(int *arr, int start, int end){
    while(start<end){
        int temp = arr[start];
        arr[start++] = arr[end];
        arr[end--] = temp;
    }
}

void ____rotate(int *arr,int length,int shift){
    shift = shift % length;
    if(!length || !shift) return;
    reverse(arr,0,shift-1);
    reverse(arr,shift,length-1);
    reverse(arr,0,length-1);
}

//006) reversal algorithm for right rotation space O(1) and time O(n)
void _____rotate(int *arr,int length,int shift){
    shift = length - (shift % length);
    if(!length || !shift) return;
    reverse(arr,0,shift-1);
    reverse(arr,shift,length-1);
    reverse(arr,0,length-1);
}

//007) block swap algorithm for left rotation space O(1) and time O(n)
void _swap(int *arr,int aIdx, int bIdx, int k){
    for(int i=0;i<k;i++){
        int temp = arr[aIdx + i];
        arr[aIdx + i] = arr[bIdx+i];
        arr[bIdx+i] = temp;
    }
}

void rotateBlock(int *arr,int length,int shift){
    shift = shift % length;
    if(!shift || !length) return;
    int A = shift, B = length-shift;
    while(A != B){
        if(A<B){
            _swap(arr,shift-A,shift-A+B,A);
            B-=A;
        }else{
            _swap(arr,shift-A,shift,B);
            A-=B;
        }
    }
    _swap(arr,shift-A,shift,A);
}

//008) block swap algorithm for right rotation space O(1) and time O(n)
void _rotateBlock(int *arr,int length,int shift){
    shift = length - (shift%length);
    if(!shift || !length) return;
    int A = shift, B = length-shift;
    while(A != B){
        if(A<B){
            _swap(arr,shift-A,shift-A+B,A);
            B-=A;
        }else{
            _swap(arr,shift-A,shift,B);
            A-=B;
        }
    }
    _swap(arr,shift-A,shift,A);
}

int main(){
    int arr[5] = {1,2,3,4,5}, length = sizeof(arr)/sizeof(int), shift = 2;
//    _____rotate(arr,length,shift);
    _rotateBlock(arr,length,shift);
    for(int i=0;i<length;i++) cout<< arr[i] << "  ";
    return 0;
}
