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

int main(){
    string name = "rajan";
//    cout << name << endl;
//    cout << name.substr(1,name.length() -2);
//    cout << recursive(name);
    cout << isPalindrome("rajjar");
    return 0;
}