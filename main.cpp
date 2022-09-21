#include <iostream>

using namespace  std;

template<class A>
void f(A a){
    cout<<1<<endl;
}
void f(int a){cout <<2<<endl;}


int main() {
    int a=1;
    f<float>(a);
    return 0;
}
