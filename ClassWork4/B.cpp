#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    int *ptr;
    cout<<"Length of array:"<<" "<<endl;
    cin>>n;
    ptr = new int[n];
    //int array[n] = {0};
    cout<<"Enter array"<<endl;
    for (int i = 0; i < n; i++){
        cin>>ptr[i];
    }
    cout<<endl;
    for (int i = n - 1 ; i >= 0; i--){
        cout<<ptr[i]<<" ";
    }
    delete[] ptr;
    cout<<endl;

    return 0;
}