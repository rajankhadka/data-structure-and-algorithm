//
// Created by react-rajan on 11/24/22.
//
#include <iostream>

using namespace std;
//time O(n) and space O(1)
bool validateSequence(const int *arr, const int *seq, int arrCount, int seqCount){
    int ptx = 0;
    for(int i =0; i< arrCount;i++) if(seq[ptx] == arr[i]) ptx++;
    if(ptx == seqCount) return true;
    return false;
}

int main(){
    int arr[8] = {5,1,22,25,6,-1,8,10},
        seq[4] = {1,6,-1,10},
        seqCount = sizeof(seq)/ sizeof (int),
        arrCount = sizeof(arr)/sizeof(int);

    cout << validateSequence(arr,seq,arrCount,seqCount);
    return 0;
}