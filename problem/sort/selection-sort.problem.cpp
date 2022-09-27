//
// Created by react-rajan on 9/27/22.
//
#include <iostream>
#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> array) {
    // Write your code here.
    for(int i=0;i<array.size();i++){
        int minIdx = i;
        for(int j=i+1;j<array.size();j++){
            if(array[minIdx] > array[j]){
                minIdx = j;
            }
        }
        int temp = array[minIdx];
        array[minIdx] = array[i];
        array[i] = temp;
    }
    return array;
}


int main(){
    vector<int> data{3,0,-1};
    data = selectionSort(data);
    for(const int& i: data){
        cout << i << "   ";
    }
}