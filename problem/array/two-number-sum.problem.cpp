//
// Created by react-rajan on 11/24/22.
//

#include <iostream>
#include<map>
#include<unordered_map>
using namespace std;

//time O(n2) space O(1)
int *twoNumberSum(int *arr, int length, int target){
    int *result = (int *)malloc(2* sizeof (int));
    for(int i=0;i<length - 1; i++){
        int firstNum = arr[i];
        for(int j=i+1; j< length;j++){
            if(target == firstNum + arr[j]){
                result[0] = firstNum;
                result[1] = arr[j];
                return result;
            }
        }
    }
    return {};
}

bool _twoNumberSum(int *arr, int length, int target){
    std::unordered_map<int, bool> unorderedMap;
    for(int i=0;i<length;i++){
        int result = target - arr[i];
        if(unorderedMap[result]){
            return true;
        }
        unorderedMap[arr[i]] = true;
    }
    return false;
}

int main(){
    int arr[8] = {3,5,-4,8,11,1,-1,6}, length = sizeof(arr)/sizeof(int);
//    int *result = twoNumberSum(arr,length,10);
//    if(result){
//        for(int i=0;i<2;i++) cout << result[i] << '\t';
//    }

    cout << _twoNumberSum(arr, length, 15);

    return 0;
}
