//
// Created by react-rajan on 9/27/22.
//

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int start, int mid, int end){
    int i = start, j = mid+1, k=0;
    int *temp = (int*)malloc((end-start+1)*sizeof(int));
    while(i<=mid && j<=end){
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }

    while(i<=mid) temp[k++]= arr[i++];
    while(j<=end) temp[k++] = arr[j++];

    for(i=start;i<=end;i++){
        arr[i] = temp[i-start];
    }
    delete[] temp;
}

void divide(vector<int> &arr, int start, int end){
    if(start< end){
        int mid = int((start+end)/2);
        divide(arr,start,mid);
        divide(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}

vector<int> mergeSort(vector<int> array) {
    // Write your code here.
    size_t end = array.size();
    divide(array,0,end-1);
    return array;
}

int main(){
    vector<int> data{4,1,5,2,-1,3,0,6};
    for(const int &i:data){
        cout << i << "   ";
    }
    cout << endl;
    data = mergeSort(data);
    for(const int &i:data){
        cout << i << "   ";
    }
    cout << endl;
    return 0;
}
