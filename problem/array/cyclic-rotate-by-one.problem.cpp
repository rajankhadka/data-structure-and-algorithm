//
// Created by react-rajan on 10/17/22.
//
#include <iostream>

using namespace std;

//001) using two pointer time O(n) and space O(1)
void swap(int *arr, int &first, int second){
    int temp = arr[first];
    arr[first++] = arr[second];
    arr[second] = temp;
}

void rotate(int *arr, int length){
    int start = 0, end = length-1;
    while(start < end){
        swap(arr, start,end);
    }
}


int main(){
    int arr[5] = {1,2,3,4,5}, length = sizeof(arr)/sizeof(int);
    rotate(arr,length);
    for(int i=0;i<length;i++) cout<< arr[i] << "  ";
    return 0;
}