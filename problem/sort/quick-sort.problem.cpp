//
// Created by react-rajan on 9/28/22.
//
#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &arr, int firstIdx, int secondIdx){
    int temp = arr[firstIdx];
    arr[firstIdx] = arr[secondIdx];
    arr[secondIdx] = temp;
}

int partition(vector<int> &arr, int start, int end){
    int pIdx = start, pValue = arr[end];
    for(int i=start;i<end;i++){
        if(arr[i] < pValue){
            swap(arr,i,pIdx);
            pIdx++;
        }
    }
    swap(arr,pIdx,end);
    return pIdx;
}

void quickSort(vector<int> &arr,int start, int end){
    if(start >= end) return;
    //find pivot;
    int pIdx = partition(arr,start,end);
    quickSort(arr, start,pIdx-1);
    quickSort(arr, pIdx+1, end);
}


int main(){
    vector<int> data{4,1,5,2,-1,3,0,6};
//    cout << data.size();
    for(const int &i:data){
        cout << i << "   ";
    }
    cout << endl;
    quickSort(data, 0, data.size()-1);
    for(const int &i:data){
        cout << i << "   ";
    }
    cout << endl;
}