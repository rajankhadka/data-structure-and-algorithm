//
// Created by rajan khadka on 25/09/2022.
//

#include <iostream>
#include<string>

using namespace std;

string recursive(string name){
    if(name == ""){
        return "";
    }
    return recursive(name.substr(1)) + name[0];
}

bool isPalindrome(string input){
    if(input.length() == 0 || input.length() == 1) return true;
    if(input[0] == input[input.length() - 1]) return isPalindrome(input.substr(1, (input.length())-2));
    return false;
}

string decimalToBinary(int decimal, string result){
    if(decimal == 0) return result;
    result = to_string(decimal % 2) + result;
    return decimalToBinary(int(decimal/2), result);
}

int sumNaturalNumber(int number){
    if(number == 1) return number;
    return number + sumNaturalNumber(number - 1);
}

int binarySearch(const int *arr, int left, int right, int search){
    if(left > right) return -1;
    int mid = int((left+right)/2);
    if(search == *(arr+mid)) return mid;
    if(search > *(arr+mid)) return binarySearch(arr,(mid+1),right,search);
    return binarySearch(arr,left, (mid-1), search);
}

//fibonacci with not optimized
long fib(long number){
    if(number == 0 || number == 1) return number;
    return fib(number-1) + fib(number-2);
}

void merge(int *arr, int start, int mid, int end){
    int i=start, j=mid+1, k=0;
    int *temp = new int[end-start+1];

    while(i<=mid && j<= end){
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }

    while(i<=mid) temp[k++] = arr[i++];
    while(j<=end) temp[k++] = arr[j++];

    for(i=start;i<=end;i++) arr[i] = temp[i-start];

    delete[] temp;
}

void mergeSort(int *arr, int start, int end){
    if(start<end){
        int mid = int((start+end)/2);
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}

int main(){
    string name = "rajan";
//    cout << name << endl;
//    cout << name.substr(1,name.length() -2);
//    cout << recursive(name);
//    cout << isPalindrome("rajjar");
//    cout << decimalToBinary(11, "");
//    cout << sumNaturalNumber(3);
//    int arr[7] = {-1,0,4,6,9,10,12};
//    cout<<binarySearch(arr, 0,(sizeof(arr)/sizeof(int)),5);
//    cout << fib(3);
    int arr[3] = {3,0,-1};
    mergeSort(arr,0,(sizeof(arr)/sizeof(int)));
    for(int i=0; i<3;i++) cout << *(arr+i) << "  ";
    cout << endl;
    return 0;

}