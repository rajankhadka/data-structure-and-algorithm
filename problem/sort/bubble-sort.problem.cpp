//
// Created by react-rajan on 9/27/22.
//
#include<iostream>
#include <vector>
using namespace std;
//optimized method
vector<int> bubbleSort(vector<int> array) {
    // Write your code here.
    size_t length = array.size();
    bool isSwapped = false;
    for(int i=0;i<length;i++){
        for(int j=0; j<length-1-i;j++){
            if(array[j]>array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                isSwapped = true;
            }
        }
        if(!isSwapped) break;
    }
    return array;
}


//bubble sort using 1 while and 1 for loop
vector<int> _bubbleSort(vector<int> array){
    bool isSwapped = true;
    while(isSwapped){
        isSwapped = false;
        for(int i =0;i< array.size() -1 ;i++){
            if(array[i] > array[i+1]){
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                isSwapped = true;
            }
        }
    }
    return array;
}


int main(){
    vector<int> data{4,1,5,2,-1,3,0,6};
    data = _bubbleSort(data);
    for(const int&i :data){
        cout << i << "  ";
    }
    cout << endl;
    return 0;
}