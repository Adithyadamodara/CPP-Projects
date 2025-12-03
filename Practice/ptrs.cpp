#include <iostream>
using namespace std;

int main(){
    int arr[] = {10,20,30,40,50};
    int *ptr = arr;
    cout<<"arr: "<<arr<<endl;
    cout<<"*ptr: "<<*ptr<<endl;
    cout<<"ptr: "<<ptr<<endl;  
    cout<<*(++ptr)<<endl;
    return 0;
}