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
    cout << fib(3);
    return 0;
}