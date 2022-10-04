//
// Created by rajan khadka on 27/09/2022.
//

#include <iostream>
#include <vector>

using namespace std;

void swapValue(vector<int> &array, int i, int ptr){
    int temp = array[i];
    array[i] = array[ptr];
    array[ptr] = temp;
}

//time complexity O(n) and space complexity O(1)
//method 1 using 2 different for loop
vector<int> threeNumberSort(vector<int> array, vector<int> order){
    if(order.empty() || array.empty()) return array;
    int firstOrder = order[0], thirdOrder = order[order.size()-1];
    int firstPtr = 0; size_t thirdPtr = array.size() -1;
    //first order
    for(int i=0;i<array.size(); i++){
        if(firstOrder == array[i]){
            //then swap
            swapValue(array, i, firstPtr);
            firstPtr++;
        }
    }

    //third order
    for(int i=int(thirdPtr); i>= 0;i--){
        if(thirdOrder == array[i]){
            //then swap
            swapValue(array,i,int(thirdPtr));
            thirdPtr--;
        }
    }
    return array;
}
//time complexity O(n) and space complexity O(1)
//method 2 using 3 ptr but using one loop
vector<int> _threeNumberSort(vector<int> array, vector<int> order){
    if(order.empty() || array.empty()) return array;
    int firstOrder = order[0], secondOrder = order[1];
    int firstPtr = 0,secondPtr = 0; size_t thirdPtr = array.size() -1;

    while(secondPtr <= thirdPtr){
        int value = array[secondPtr];
        if(value == firstOrder){
            swapValue(array, firstPtr,secondPtr);
            firstPtr++; secondPtr++;
        }else if(value == secondOrder){
            secondPtr++;
        }else{
            swapValue(array,secondPtr,int(thirdPtr));
            thirdPtr--;
        }
    }
    return array;
}

//method3
vector<int> __threeNumberSort(vector<int> array, vector<int> order){
    int leftPtr= 0;
    for(int i=0; i< int(order.size()); i++){
        for(int j=0;j<int(array.size()); j++){
            if(order[i] == array[j]){
                swapValue(array,j,leftPtr);
                leftPtr++;
            }
        }
    }
    return array;
}

int main(){
    vector<int> array{0, 1};
    vector<int> order{0,1,2};
    array = _threeNumberSort(array,order);
    for(const int &i:array){
        cout << i << "   ";
    }
    return 0;
}
