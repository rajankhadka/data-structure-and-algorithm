//
// Created by react-rajan on 9/27/22.
//
#include <iostream>
#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> array) {
    for(int i=1; i< array.size();i++){
        int key = array[i];
        int index = i;

        while(index>0 && array[index-1]>key){
            array[index] = array[index-1];
            index = index-1;
        }
        array[index] = key;
    }
    return array;
}

int main(){
    vector<int> data{3,0,-1};
    data = insertionSort(data);
    for(const int& i: data){
        cout << i << "   ";
    }
}