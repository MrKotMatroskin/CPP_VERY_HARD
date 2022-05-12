#include <iostream>
using namespace std;
int main() {
    int a = 0;
    int c = 0;
    cin>>a;
    while (a>=98){
        a=a-98;
        c++;
    }
    while (a>=49){
        a=a-49;
        c++;
    }
    while (a>=7){
        a=a-7;
        c++;
    }
    while (a>=1){
        a=a-1;
        c++;
    }
    cout<<c;
    return 0;
}
